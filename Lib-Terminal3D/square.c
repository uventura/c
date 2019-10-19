#include "lib/header3D.c"

int main()
{
	struct screen tela;
	struct coord3D square[4], copy[4], center_mass;

	clock_t ti;
	double delta_t;

	init(&tela, 40, 20, '.');

	/* Square */
	square[0] = set_point(0, 0, 0);
	square[1] = set_point(2, 0, 0);
	square[2] = set_point(2, 2, 0);
	square[3] = set_point(0, 2, 0);

	/* Index Buffer */
	int elements = 8;
	unsigned int ibo[8] = 
	{
		0, 1,
		1, 2,
		2, 3,
		3, 0
	};

	/* Initial Transformations */
	translate(square, 4, 10, 10, 10);

	center_mass = centerObj(square, 4);
	translate(square, 4, -center_mass.x, -center_mass.y, -center_mass.z);
		scale(square, 4, 4, 4, 4);
	translate(square, 4, center_mass.x, center_mass.y, center_mass.z);

	copy_array(square, copy, 4);

	ortographic(square, 4);

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
			translate(square, 4, -center_mass.x, -center_mass.y, -center_mass.z);
				rotate(square, 4, 0, 0, ang);
			translate(square, 4, center_mass.x, center_mass.y, center_mass.z);

			ortographic(square, 4);

			r = build_lines(square, ibo, elements, &size_r);
			ortographic(r, size_r);

			clr_scr(&tela);
				point_to_scr(&tela, r, size_r);
			show_scr(tela);

			copy_array(copy, square, 4);

			ang++;
			ti = clock();
		}
	}
}