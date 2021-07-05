// O programa modifica imagens BMP através das cores de seus Pixels.

#include <stdio.h>

typedef struct
{
	unsigned char header[54];
	unsigned int dataPos;
	unsigned int Width, Height;
	short int BPP;
	int Compression;
	unsigned int ImageSize;
}BMP_HEADER;


int main()
{
	FILE* img = fopen("passaro.bmp", "rwb");

	if(!img)
	{
		printf("A imagem nao pode ser aberta.\n");
		return 1;
	}

	BMP_HEADER image;

	if(fread(image.header, 1, 54, img) != 54)
	{
		printf("Nao e um arquivo BMP.\n");
		return 1;
	}
	else if(image.header[0] != 'B' || image.header[1] != 'M')
	{
		printf("Nao e um arquivo BMP.\n");
	}
	else
	{
		image.dataPos = *(int*)&(image.header[0x0A]);
		image.ImageSize = *(int*)&(image.header[0x22]);
		image.Width = *(int*)&(image.header[0x12]);
		image.Height = *(int*)&(image.header[0x16]);
		image.BPP = *(int*)&(image.header[0x1C]);
		image.Compression = *(int*)&(image.header[0x1E]);
	}

	// Modifica Imagem
	unsigned char bgr[image.ImageSize];
	fread(bgr, 1, image.ImageSize, img);	

	int i;
	unsigned char save;

	for(i = 0; i < image.ImageSize; i+=3)
	{
		// bgr[i] => Blue (Azul)
		// bgr[i+1] => Green (Verde)
		// bgr[i+2] => Red (Vermelho)
		
		save = bgr[i];

		bgr[i] = bgr[i+2];
		bgr[i+2] = save;
		bgr[i+1] = bgr[i];
	}

	// Nova Imagem
	FILE* newImg = fopen("filtro.bmp", "wb");
	
	fwrite(image.header, sizeof(image.header), 1, newImg);
	fwrite(bgr, sizeof(bgr), 1, newImg);

	fclose(newImg);
	fclose(img);

	printf("Imagem Modificada!\n");

	return 0;
}