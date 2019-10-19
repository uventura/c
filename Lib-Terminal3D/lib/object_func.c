/* Object Settings*/

struct coord3D set_point(float px, float py, float pz)
{
	struct coord3D n_Point;

	n_Point.x = px;
	n_Point.y = py;
	n_Point.z = pz;

	return n_Point;
}

void point_to_scr(struct screen *scr, struct coord3D *points, int size)
{
	int i;

	for(i = 0; i < size; ++i)
	{
		if(points[i].x >= 0 && points[i].x < scr->width && points[i].y >= 0 && points[i].y < scr->height)
			scr->elements[scr->height - (int)points[i].y - 1][(int)points[i].x] = 'O';
	}
}

struct coord3D centerObj(struct coord3D *points, int size)
{
	int i;
	
	struct coord3D center;
	center.x = 0;
	center.y = 0;
	center.z = 0;

	for(i = 0; i < size; ++i)
	{
		center.x += points[i].x;
		center.y += points[i].y;
		center.z += points[i].z;
	}

	center.x = center.x / size;
	center.y = center.y / size;
	center.z = center.z / size;

	return center;
}

/* Build Rule */
struct coord3D *build_lines(struct coord3D *points, unsigned int *Ibuffer, int n, int *size_r)
{
	*size_r = 0;

	struct coord3D *result;
	result = malloc(sizeof(struct coord3D));

	float px, py, pz, coef1[2], coef2[2], max, min, j;

	int i, pos = -1, ib = 0;

	for(i = 0; i < n - 1; i = i + 2)
	{
		/*
		if(i + 1 == n)
		{
			px = points[0].x;
			py = points[0].y;
			pz = points[0].z;
		}
		else
		{
			px = points[i+1].x;
			py = points[i+1].y;
			pz = points[i+1].z;
		}*/

		px = points[Ibuffer[i+1]].x;
		py = points[Ibuffer[i+1]].y;
		pz = points[Ibuffer[i+1]].z;

		ib = Ibuffer[i];

		max = points[ib].x;
		min = px;

		if(points[ib].x - px == 0)
		{
			coef1[0] = 1;
			coef1[1] = 1;

			coef2[0] = 0;
			coef2[1] = 0;

			max = points[ib].y;
			min = py;
		}
		else
		{
			coef1[0] = (points[ib].y - py) / (points[ib].x - px);
			coef1[1] = (points[ib].z - pz) / (points[ib].x - px);

			coef2[0] = py - coef1[0] * px;
			coef2[1] = pz - coef1[1] * px;
		}


		if(min > max)
		{
			min = min + max;
			max = min - max;
			min = min - max;
		}

		j = min;
		while(j <= max)
		{
			pos++;

			result[pos].x = j;
			if(points[ib].x - px == 0)
				result[pos].x = px;

			result[pos].y = (j * coef1[0]) + coef2[0];
			result[pos].z = (j * coef1[1]) + coef2[1];

			result = realloc(result, (pos + 2) * sizeof(struct coord3D));

			*size_r = pos + 1;

			j = j + 0.1;
		}
	}

	return result;
}

void copy_array(struct coord3D *a1, struct coord3D *a2, int size)
{
	int i;
	for(i = 0; i < size; i++)
	{
		a2[i] = a1[i];
	}
}