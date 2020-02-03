/**
 * 任意の縦横幅の平面メッシュ(wavefrontのobj形式)を作成するプログラム
 * しばらくCを触っていなかったため試作
 * PNG解析とかを後に予定している。この辺りはCでやるよりC#とかの方が楽そう
 */
#include "stdafx.h"

static const char* DEFINE_OUTFILEPATH = "C:\\git\\work\\testplane.obj";	/* 出力先 */
static const int DEFINE_WIDTH = 64;										/* 平面幅 */
static const int DEFINE_HEIGHT = 48;									/* 平面幅 */

int main()
{
	/*
	 * ファイルオープンし、出力先ファイルに書き込む準備をする
	 */
	FILE *outputfile;									/* 出力ストリーム */
	outputfile = fopen( DEFINE_OUTFILEPATH, "w" );		/* ファイルを書き込み用にオープン(開く) */
	if (outputfile == NULL) {							/* オープンに失敗した場合 */
		printf("cannot open\n");						/* エラーメッセージを出して */
		return 1;										/* 異常終了 */
	}

	/*
	 * wavefront形式(*.obj)で(Width×Height)のメッシュを作成する(XY平面)
	 * Vertexを作成した後にMeshの面を定義する
	 * 一枚のテクスチャを平面に貼り付けたように表示されるように作成する
	 * XY平面でZ軸に関しては特に設定せずに作成する
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
	 * ファイルクローズし、
	 * プログラムを終了する
	 */
	fclose(outputfile);          /* ファイルをクローズ(閉じる) */
    return 0;
}

