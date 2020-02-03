/**
 * �C�ӂ̏c�����̕��ʃ��b�V��(wavefront��obj�`��)���쐬����v���O����
 * ���΂炭C��G���Ă��Ȃ��������ߎ���
 * PNG��͂Ƃ�����ɗ\�肵�Ă���B���̕ӂ��C�ł����C#�Ƃ��̕����y����
 */
#include "stdafx.h"

static const char* DEFINE_OUTFILEPATH = "C:\\git\\work\\testplane.obj";	/* �o�͐� */
static const int DEFINE_WIDTH = 64;										/* ���ʕ� */
static const int DEFINE_HEIGHT = 48;									/* ���ʕ� */

int main()
{
	/*
	 * �t�@�C���I�[�v�����A�o�͐�t�@�C���ɏ������ޏ���������
	 */
	FILE *outputfile;									/* �o�̓X�g���[�� */
	outputfile = fopen( DEFINE_OUTFILEPATH, "w" );		/* �t�@�C�����������ݗp�ɃI�[�v��(�J��) */
	if (outputfile == NULL) {							/* �I�[�v���Ɏ��s�����ꍇ */
		printf("cannot open\n");						/* �G���[���b�Z�[�W���o���� */
		return 1;										/* �ُ�I�� */
	}

	/*
	 * wavefront�`��(*.obj)��(Width�~Height)�̃��b�V�����쐬����(XY����)
	 * Vertex���쐬�������Mesh�̖ʂ��`����
	 * �ꖇ�̃e�N�X�`���𕽖ʂɓ\��t�����悤�ɕ\�������悤�ɍ쐬����
	 * XY���ʂ�Z���Ɋւ��Ă͓��ɐݒ肹���ɍ쐬����
	 */
	const int width = DEFINE_WIDTH;
	const int height = DEFINE_HEIGHT;

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

			// if (i > 10 && i < 40) y += (i-10);
			// if (j > 10 && j < 32) y += (j-10);

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
		}
	}

	/*
	 * �t�@�C���N���[�Y���A
	 * �v���O�������I������
	 */
	fclose(outputfile);          /* �t�@�C�����N���[�Y(����) */
    return 0;
}

