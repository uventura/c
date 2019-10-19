#include "lib/header3D.c"

int main()
{
	struct screen tela;
	struct coord3D form[8], copy[8], center_mass;
	float angle;

	init(&tela, 40, 40, ' ');

	/* Front */
	form[0] = set_point(0, 0, 0);
	form[1] = set_point(2, 0, 0);
	form[2] = set_point(2, 3, 0);
	form[3] = set_point(0, 3, 0);
	/* Back */
	form[4] = set_point(0, 0, 4);
	form[5] = set_point(2, 0, 4);
	form[6] = set_point(2, 3, 4);
	form[7] = set_point(0, 3, 4);

	/* Index Buffer */
	unsigned int ibo[24] = {
		0, 1,
		1, 2,
		2, 3,
		3, 0,
		0, 4,
		4, 5,
		5, 6,
		6, 7,
		7, 4,
		1, 5,
		2, 6,
		7, 3
	};

	/* Initial Transformations */
	translate(form, 8, 10, 10, 10);

	center_mass = centerObj(form, 8);

	translate(form, 8, -center_mass.x, -center_mass.y, -center_mass.z);
		scale(form, 8, 6, 3, 3);
		rotate(form, 8, 37, 0, 0);
	translate(form, 8, center_mass.x, center_mass.y, center_mass.z);

	copy_array(form, copy, 8);

	ortographic(form, 8);

	/* Resultant Matrix */
	int size_r;
	struct coord3D *r;
	/*------*/

	clock_t ti;
	double delta_t;

	ti = clock();
	angle = 0;

	while(1)
	{
		delta_t = (double)(clock() - ti) / CLOCKS_PER_SEC;
		if(delta_t >= 0.01)
		{
			translate(form, 8, -center_mass.x, -center_mass.y, -center_mass.z);
				rotate(form, 8, angle, angle, angle);
			translate(form, 8, center_mass.x, center_mass.y, center_mass.z);

			ortographic(form, 8);

			r = build_lines(form, ibo, 24, &size_r);

			ortographic(r, size_r);

			clr_scr(&tela);
				point_to_scr(&tela, r, size_r);
			show_scr(tela);

			copy_array(copy, form, 8);

			angle++;
			ti = clock();
		} 
	}
}