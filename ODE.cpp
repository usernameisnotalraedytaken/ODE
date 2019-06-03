#include<bits/stdc++.h>
#define eps 1e-11
using namespace std;
double f(double x, double y)
{
	return 2 * x;
}
/**
x, y: Init val
h: step length.
*/
double Euler(double x, double y, double h)
{
	double Yn = y + h * f(x, y);
}
double MEuler(double x, double y, double h)
{
	double Yn = y + h * f(x + h / 2.0, y + h / 2.0 * f(x, y));
	return Yn;
}
double RK2(double x, double y, double h)
{
	double Yn = y + h / 2.0 * (f(x, y) + f(x + h, y + h * f(x, y)));
	return Yn;
}
double RK4(double x, double y, double h)
{
	double K1 = f(x, y);
	double K2 = f(x + h / 2.0, y + h / 2.0 * K1);
	double K3 = f(x + h / 2.0, y + h / 2.0 * K2);
	double K4 = f(x + h, y + h * K3);
	double Yn = y + h / 6.0 * (K1 + 2.0 * K2 + 2.0 * K3 + K4);
	return Yn;
}


int plot[500][500];


#define SVPNG_INC_
#define SVPNG_LINKAGE
#define SVPNG_OUTPUT FILE* fp
#define SVPNG_PUT(u) fputc(u, fp)
SVPNG_LINKAGE void svpng(SVPNG_OUTPUT, unsigned w, unsigned h, const unsigned char* img, int alpha) {
    static const unsigned t[] = { 0, 0x1db71064, 0x3b6e20c8, 0x26d930ac, 0x76dc4190, 0x6b6b51f4, 0x4db26158, 0x5005713c, 
    /* CRC32 Table */    0xedb88320, 0xf00f9344, 0xd6d6a3e8, 0xcb61b38c, 0x9b64c2b0, 0x86d3d2d4, 0xa00ae278, 0xbdbdf21c };
    unsigned a = 1, b = 0, c, p = w * (alpha ? 4 : 3) + 1, x, y, i;   /* ADLER-a, ADLER-b, CRC, pitch */
#define SVPNG_U8A(ua, l) for (i = 0; i < l; i++) SVPNG_PUT((ua)[i]);
#define SVPNG_U32(u) do { SVPNG_PUT((u) >> 24); SVPNG_PUT(((u) >> 16) & 255); SVPNG_PUT(((u) >> 8) & 255); SVPNG_PUT((u) & 255); } while(0)
#define SVPNG_U8C(u) do { SVPNG_PUT(u); c ^= (u); c = (c >> 4) ^ t[c & 15]; c = (c >> 4) ^ t[c & 15]; } while(0)
#define SVPNG_U8AC(ua, l) for (i = 0; i < l; i++) SVPNG_U8C((ua)[i])
#define SVPNG_U16LC(u) do { SVPNG_U8C((u) & 255); SVPNG_U8C(((u) >> 8) & 255); } while(0)
#define SVPNG_U32C(u) do { SVPNG_U8C((u) >> 24); SVPNG_U8C(((u) >> 16) & 255); SVPNG_U8C(((u) >> 8) & 255); SVPNG_U8C((u) & 255); } while(0)
#define SVPNG_U8ADLER(u) do { SVPNG_U8C(u); a = (a + (u)) % 65521; b = (b + a) % 65521; } while(0)
#define SVPNG_BEGIN(s, l) do { SVPNG_U32(l); c = ~0U; SVPNG_U8AC(s, 4); } while(0)
#define SVPNG_END() SVPNG_U32(~c)
    SVPNG_U8A("\x89PNG\r\n\32\n", 8);           /* Magic */
    SVPNG_BEGIN("IHDR", 13);                    /* IHDR chunk { */
    SVPNG_U32C(w); SVPNG_U32C(h);               /*   Width & Height (8 bytes) */
    SVPNG_U8C(8); SVPNG_U8C(alpha ? 6 : 2);     /*   Depth=8, Color=True color with/without alpha (2 bytes) */
    SVPNG_U8AC("\0\0\0", 3);                    /*   Compression=Deflate, Filter=No, Interlace=No (3 bytes) */
    SVPNG_END();                                /* } */
    SVPNG_BEGIN("IDAT", 2 + h * (5 + p) + 4);   /* IDAT chunk { */
    SVPNG_U8AC("\x78\1", 2);                    /*   Deflate block begin (2 bytes) */
    for (y = 0; y < h; y++) {                   /*   Each horizontal line makes a block for simplicity */
        SVPNG_U8C(y == h - 1);                  /*   1 for the last block, 0 for others (1 byte) */
        SVPNG_U16LC(p); SVPNG_U16LC(~p);        /*   Size of block in little endian and its 1's complement (4 bytes) */
        SVPNG_U8ADLER(0);                       /*   No filter prefix (1 byte) */
        for (x = 0; x < p - 1; x++, img++)
            SVPNG_U8ADLER(*img);                /*   Image pixel data */
    }
    SVPNG_U32C((b << 16) | a);                  /*   Deflate block end with adler (4 bytes) */
    SVPNG_END();                                /* } */
    SVPNG_BEGIN("IEND", 0); SVPNG_END();        /* IEND chunk {} */
}
void test_rgb(void) {
    unsigned char rgb[500 * 500 * 3], *p = rgb;
    unsigned x, y;
    FILE *fp = fopen("rgb5.png", "wb");
    for (y = 0; y < 500; y++)
        for (x = 0; x < 500; x++) {
        	int a = plot[y][x];
        	if(a == 1)
        	{
        		*p++ = (unsigned int)a * 255;    /* R */
            	*p++ = (unsigned int)a * 255;    /* G */
           		*p++ = (unsigned int)a * 255;    /* B */
			}
            else if(a == 2)
            {

            	*p++ = (unsigned int)a * 255;    /* R */
            	*p++ = 0;
            	*p++ = 0;
			}
			else if(a == 3)
			{
				*p++ = 0;
            	*p++ = (unsigned int)a * 255;    /* G */
            	*p++ = 0;
			}
			else if(a == 4)
			{
				*p++ = 0;
				*p++ = 0;
            	*p++ = (unsigned int)a * 255;    /* B */
			}
        }
    svpng(fp, 500, 500, rgb, 0);
    fclose(fp);
}


double max(double *a)
{
	double m = 0xffffffff;
	for(int i = 0 ;i < 500; ++i)if(a[i]>m)m=a[i];
	return m;
}



int main()
{
	double x = eps,y10 = eps, y11 = y10, y12 = y10, y13 = y10, h = 0.001;
	cout << "x : " << x << endl;
	cout << "y : " << y10 << endl;
	cout << "h : " << h << endl;
	cout << "Euler\tM-Euler\tRK2\tRK4" << endl;
	double y01[500], y21[500], y31[500], y41[500];
	for(int i = 0; i < 500; ++i)
	{
		y41[i] = y11 = RK4(x, y11, h);
		y21[i] = y12 = RK2(x, y12, h);
		y31[i] = y13 = MEuler(x, y13, h);
		y01[i] = y10 = Euler(x, y10, h);
		x += h; 
		//printf("%.5lf\t%.5lf\t%.5lf\t%.5lf\n", y10, y13, y12, y11);
	}
	double m[500] = {max(y01), max(y21), max(y31), max(y41)};
	int maxx = max(m);
	double xx = 500.0 / maxx;
	cout << "xx = " << xx << endl;
	for(int i = 0; i < 500; ++i)
	{
		int xy41 = (int)y41[i] * xx;
		int xy21 = (int)y21[i] * xx;
		int xy31 = (int)y31[i] * xx;
		int xy01 = (int)y01[i] * xx;
		plot[i][xy41] = 1;
		plot[i][xy21] = 2;
		plot[i][xy31] = 3;
		plot[i][xy01] = 4;
		printf("%d", xy41);
	}
	test_rgb();
	system("rgb5.png");
}
