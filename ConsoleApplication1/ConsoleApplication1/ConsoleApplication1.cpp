
#include "stdafx.h"


int main()
{
	printf("Hello World.");

	FILE *outputfile;         // �o�̓X�g���[��

	outputfile = fopen( "C:\\Users\\chubachi\\Desktop\\Natsuki_Work\\3d_obj_test\\testplane02.obj", "w" );		// �t�@�C�����������ݗp�ɃI�[�v��(�J��)
	if (outputfile == NULL) {				// �I�[�v���Ɏ��s�����ꍇ
		printf("cannot open\n");			// �G���[���b�Z�[�W���o����
		return 1;							// �ُ�I��
	}

	//fprintf(outputfile, "My name is Enokida Yuuichirou.\n"); // �t�@�C���ɏ���

	const int width = 640;	//64; //640
	const int height = 480;	//48; //480

	fprintf(outputfile, "mtllib untitled.mtl\n");
	fprintf(outputfile, "o Plane\n");

	for (int i = 0; i <= width; i++)
	{
		for (int j = 0; j <= height; j++)
		{
			double x = (double)( -(width/2) + i );
			double y = (double)( 0 );
			double z = (double)( -(height/2) + j );
			double vx = 0.0 + (1.0 * i / width);
			double vy = 0.0 - (1.0 * j / height);

			if (i > 10 && i < 40) y += (i-10);
			if (j > 10 && j < 32) y += (j-10);

			fprintf(outputfile, "v %f %f %f\n", x, y, z);
			fprintf(outputfile, "vt %f %f\n", vx, vy);
		}
	}

	fprintf(outputfile, "vn %f %f %f\n", 0.0, 0.0, 1.0);

	fprintf(outputfile, "usemtl None\n");
	fprintf(outputfile, "s off\n");

	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
		{
			int offset = (i * (height + 1)) + 1;
			fprintf(outputfile, "f %d/%d/%d %d/%d/%d %d/%d/%d %d/%d/%d\n",
				j + offset, j + offset, 1,
				j + 1 + offset, j + 1 + offset, 1,
				height + 1 + j + 1 + offset, height + 1 + j + 1 + offset, 1,
				height + 1 + j + offset, height + 1 + j + offset, 1
			);
			/*
			int offset = (j * (height +1)) + 1;
			fprintf(outputfile, "f %d/%d/%d %d/%d/%d %d/%d/%d %d/%d/%d\n",
				i + offset, i + offset, 1,
				i + 1 + offset, i + 1 + offset, 1,
				height + 1 + i + 1+ offset, height + 1 + i + 1+ offset, 1,
				height + 1 + i + offset, height + 1 + i + offset, 1
			);
			*/
		}
	}

	fclose(outputfile);          // �t�@�C�����N���[�Y(����)

    return 0;
}

