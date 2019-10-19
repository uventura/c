#include "lib/header3D.c"

int main()
{
	struct screen tela;
	struct coord3D piramide[5], copy[5], center_mass;

	clock_t ti;
	double delta_t;

	init(&tela, 40, 20, ' ');

	/* Square */
	piramide[0] = set_point(0, 0, 0);
	piramide[1] = set_point(2, 0, 0);
	piramide[2] = set_point(2, 0, 2);
	piramide[3] = set_point(0, 0, 2);
	piramide[4] = set_point(1, 2, 1);

	/* Index Buffer */
	int elements = 16;
	unsigned int ibo[16] = 
	{
		0, 1,
		1, 2,
		2, 3,
		3, 0,
		0, 4,
		1, 4,
		2, 4,
		3, 4
	};

	/* Initial Transformations */
	translate(piramide, 5, 10, 10, 10);

	center_mass = centerObj(piramide, 4);
	translate(piramide, 5, -center_mass.x, -center_mass.y, -center_mass.z);
		rotate(piramide, 5, 20, 20, 0);
		scale(piramide, 5, 6, 4, 4);
	translate(piramide, 5, center_mass.x, center_mass.y, center_mass.z);

	copy_array(piramide, copy, 5);

	ortographic(piramide, 5);

	/* Resultant Matrix */
	int size_r;
	struct coord3D *r;

	/*----------*/
	ti = clock();
	float ang = 0;

	while(1)
	{
		delta_t = (double)(clock() - ti) / CLOCKS_PER_SEC;
		if(delta_t >= 0.01)
		{
			translate(piramide, 5, -center_mass.x, -center_mass.y, -center_mass.z);
				rotate(piramide, 5, ang, ang, 0);
			translate(piramide, 5, center_mass.x, center_mass.y, center_mass.z);

			ortographic(piramide, 5);

			r = build_lines(piramide, ibo, elements, &size_r);
			ortographic(r, size_r);

			clr_scr(&tela);
				point_to_scr(&tela, r, size_r);
			show_scr(tela);

			copy_array(copy, piramide, 5);

			ang++;
			ti = clock();
		}
	}
}