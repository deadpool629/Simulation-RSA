#include<stdlib.h>
#include<GL/glut.h>
#include<stdio.h>
#include<math.h>
#include<string.h>
#define SCENE 10

enum { FRONTPAGE,ENCRYPTION,EXIT };

int width = 650, height = 650;

void *font =GLUT_BITMAP_HELVETICA_12;
void *fonts[] =
{
GLUT_BITMAP_9_BY_15,
GLUT_BITMAP_TIMES_ROMAN_10,
GLUT_BITMAP_TIMES_ROMAN_24,             // Text Styles
GLUT_BITMAP_HELVETICA_12,
GLUT_BITMAP_HELVETICA_10,
GLUT_BITMAP_HELVETICA_18,
};

// TO DISPLAY THE TEXT INFORMATION

void output(int x, int y, char *string,int j)      
{
int len, i;

glRasterPos2f(x, y);
len = (int) strlen(string);
for (i = 0; i < len; i++)
glutBitmapCharacter(fonts[j], string[i]);
}

int x, y, n, t, i, flag;
long int e[50], d[50], temp[50], j, m[50], en[50];
char msg[100],enm[50];
int prime(long int);
void encryption_key();
long int cd(long int);
void encrypt();
void decrypt();

void rsa()
{
  printf("\nENTER FIRST PRIME NUMBER\n");
  scanf("%d", &x);
  flag = prime(x);
  if(flag == 0)
  {
    printf("\nINVALID INPUT\n");
    exit(0);
  }
  printf("\nENTER SECOND PRIME NUMBER\n");
  scanf("%d", &y);
  flag = prime(y);
  if(flag == 0 || x == y)
  {
    printf("\nINVALID INPUT\n");
    exit(0);
  }
  printf("\nENTER MESSAGE OR STRING TO ENCRYPT\n");

  scanf("%s",msg);
  for(i = 0; msg[i] != NULL; i++)
    m[i] = msg[i];
  n = x * y;
  t = (x-1) * (y-1);
  encryption_key();
  printf("\nPOSSIBLE VALUES OF e AND d ARE\n");
  for(i = 0; i < j-1; i++)
    printf("\n%ld\t%ld", e[i], d[i]);
  encrypt();
  decrypt();
  return 0;
}
int prime(long int pr)
{
  int i;
  j = sqrt(pr);
  for(i = 2; i <= j; i++)
  {
   if(pr % i == 0)
     return 0;
  }
  return 1;
 }

//function to generate encryption key
void encryption_key()
{
  int k;
  k = 0;
  for(i = 2; i < t; i++)
  {
    if(t % i == 0)
     continue;
    flag = prime(i);
    if(flag == 1 && i != x && i != y)
    {
     e[k] = i;
     flag = cd(e[k]);
    if(flag > 0)
    {
     d[k] = flag;
     k++;
    }
   if(k == 99)
    break;
   }
 }
}
long int cd(long int a)
{
  long int k = 1;
  while(1)
  {
    k = k + t;
    if(k % a == 0)
     return(k / a);
  }
}

//function to encrypt the message
void encrypt()
{
  long int pt, ct, key = e[0], k, len;
  i = 0;
  len = strlen(msg);
  while(i != len)
  {
    pt = m[i];
    pt = pt - 96;
    k = 1;
    for(j = 0; j < key; j++)
    {
     k = k * pt;
     k = k % n;
    }
   temp[i] = k;
   ct = k + 96;
   en[i] = ct;
   i++;
  }
  en[i] = -1;
  printf("\n\nTHE ENCRYPTED MESSAGE IS\n");
  for(i = 0; en[i] != -1; i++){
    printf("%c", en[i]);
	enm[i]=en[i];}
}

//function to decrypt the message
void decrypt()
{
  long int pt, ct, key = d[0], k;
  i = 0;
  while(en[i] != -1)
  {
    ct = temp[i];
    k = 1;
    for(j = 0; j < key; j++)
    {
      k = k * ct;
      k = k % n;
    }
   pt = k + 96;
   m[i] = pt;
   i++;
  }
  m[i] = -1;
  printf("\n\nTHE DECRYPTED MESSAGE IS\n");
  for(i = 0; m[i] != -1; i++)
   printf("%c", m[i]);
  printf("\n");
}
// FUNCTIONS. FOR DELAY

void delay(void)
{
int i,j,k;
for(i=0;i<10;i++)
{
for(j=0;j<100;j++);
for(k=0;k<150;k++);
}
}
void delay1(void)
{
int i;
for(i=0;i<100;i++);
}


// FIRST SCREEN - FRONT PAGE
void front_page()
{
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
glMatrixMode(GL_MODELVIEW);
glPushMatrix();

output(220,550,"ATME COLLEGE OF ENGINEERING",2);

output(320,500,"A",2);
output(260,450,"MINI PROJECT ON",2);

output(210,400,"RSA ENCRYPTION AND DECRYPTION",2);

output(130,205,"Under the guidance of:",5);
output(175,180,"Miss. Kavyashree E D",2);
output(175,160,"Asst. Professor",2);
output(175,140,"Dept of CSE, ATMECE, Mysuru",2);
//output(175,150,"Name 2",2);

output(450,205,"By:",5);
output(475,180,"Rudresh RM(4AD15CS059)",2);
output(475,150,"Rakshith DM(4AD15CS062)",2);
output(275,50,"Press S to start",2);
   glFlush();
glCallList(SCENE);
glPopMatrix();
glutSwapBuffers();
glFlush();
}

/* Movement angles */
GLint movement_angle=0,packet_angle=0,head_angle=0,packet_angle1=0,head_angle1=0,packet_angle2=0,head_angle2=0,packet_angle3=0,head_angle3=0,packet_angle4=0;
GLdouble mov_speed = 1;
GLint head_angle4=0,packet_angle5=0,head_angle5=0,packet_angle6=0,head_angle6=0,packet_angle7,head_angle7=0,packet_angle8=40;



/* Movement angles */
GLint movement_angle1=0,arrow_angle=0,rev_arrow_angle=0,phy_header_angle=0,rev_phy_header_angle=0,rev_phy_header_angle1=0,phy_header_angle1=0,analog_sig_angle=0,rev_analog_sig_angle = 0;


void animation_encryp(void)
{
if ((movement_angle += mov_speed) >= 600)
movement_angle = 600;
if ((arrow_angle += mov_speed) >= 150)
arrow_angle = 150;
if(arrow_angle==150)
if ((phy_header_angle += mov_speed) >= 100)
phy_header_angle = 100;
if(phy_header_angle==100)
if ((phy_header_angle1 += mov_speed) >= 100)
phy_header_angle1 = 100;
if(phy_header_angle1==100)
if ((analog_sig_angle += mov_speed) >= 100)
analog_sig_angle = 100;
if(analog_sig_angle==100)
if ((movement_angle1 += mov_speed) >= 420)
movement_angle1 = 420;
if(movement_angle1 ==420)
if ((rev_analog_sig_angle += mov_speed) >= 100)
rev_analog_sig_angle = 100;
if(rev_analog_sig_angle ==100)
if ((rev_phy_header_angle += mov_speed) >= 200)
rev_phy_header_angle = 200;
if(rev_phy_header_angle ==200)
if ((rev_phy_header_angle1 += mov_speed) >= 100)
rev_phy_header_angle1 = 100;
if(rev_phy_header_angle ==200)
if ((rev_arrow_angle += mov_speed) >= 100)
rev_arrow_angle = 100;
glutPostRedisplay();
}


/*void computer()
{
glColor3f(0.75,0.85,0.65);//keyboard
glBegin(GL_QUADS);
glVertex2f(55.0,340.0);
glVertex2f(145.0,340.0);
glVertex2f(150.0,350.0);
glVertex2f(60.0,350.0);
glEnd();

glColor3f(0.75,0.85,0.65);//cabinet
glBegin(GL_LINE_LOOP);
glVertex2f(60.0,355.0);
glVertex2f(150.0,355.0);
glVertex2f(150.0,370.0);
glVertex2f(60.0,370.0);
glEnd();

glColor3f(0.75,0.85,0.65);
glBegin(GL_LINE_LOOP);
glVertex2f(75.0,380.0);
glVertex2f(135,380.0);
glVertex2f(135.0,430.0);
glVertex2f(75.0,430.0);
glEnd();

glColor3f(0.7,0.8,0.6);
glBegin(GL_QUADS);
glVertex2f(80.0,385.0);
glVertex2f(130.0,385.0);
glVertex2f(130.0,425.0);
glVertex2f(80.0,425.0);
glEnd();

   glColor3f(0.75,0.85,0.65);
glBegin(GL_LINES);
glVertex2f(90.0,370.0);
glVertex2f(90.0,380.0);
glVertex2f(120.0,370.0);
glVertex2f(120.0,380.0);
glEnd();
}*/

/*void computer_dest()
{
glColor3f(0.75,0.85,0.65);//keyboard
glBegin(GL_QUADS);
glVertex2f(545.0,525.0);
glVertex2f(635.0,525.0);
glVertex2f(640.0,535.0);
glVertex2f(550.0,535.0);
glEnd();

glColor3f(0.75,0.85,0.65);//cabinet
glBegin(GL_LINE_LOOP);
glVertex2f(550.0,540.0);
glVertex2f(640.0,540.0);
glVertex2f(640.0,555.0);
glVertex2f(550.0,555.0);
glEnd();

glColor3f(0.75,0.85,0.65);//cpu
glBegin(GL_LINE_LOOP);
glVertex2f(565.0,565.0);
glVertex2f(625,565.0);
glVertex2f(625.0,615.0);
glVertex2f(565.0,615.0);
glEnd();

glColor3f(0.7,0.8,0.6);//monitor
glBegin(GL_QUADS);
glVertex2f(570.0,570.0);
glVertex2f(620.0,570.0);
glVertex2f(620.0,610.0);
glVertex2f(570.0,610.0);
glEnd();

glColor3f(0.75,0.85,0.65);
glBegin(GL_LINES);
glVertex2f(580.0,555.0);
glVertex2f(580.0,565.0);
glVertex2f(610.0,555.0);
glVertex2f(610.0,565.0);
glEnd();
}*/



void cipher()
{

glColor3f(0.0f,0.0f,1.0f);
glPushMatrix();
glScalef(40,20,.5);
glTranslatef(3,9,0);
glutWireCube(2);
output(-1,0,enm,2);
glPopMatrix();

}


void message_data()
{

glColor3f(1.0f,1.0f,0.0f);
/*glPushMatrix();
glScalef(40,20,.5);
glTranslatef(3,14,0);
//glutWireCube(2);*/
glBegin(GL_LINE_LOOP);
glVertex2i(40,200);
glVertex2i(160,200);
glVertex2i(160,300);
glVertex2i(40,300);
glEnd();
glBegin(GL_POLYGON);
glVertex2i(40,300);
glVertex2i(160,300);
glVertex2i(100,270);
glEnd();
output(55,220,msg,2);
//glPopMatrix();
}


void message_key(void)
{

glColor3f(0.0f,1.0f,0.0f);
glPushMatrix();
glScalef(20,20,.5);
glTranslatef(3,14,0);
glutWireCube(2);
output(-1,0,"KEY",2);
glPopMatrix();
}

void woman()
{
	//face
/*	glColor3ub(0,0,0);
	glPushMatrix();
	glTranslatef(540,495,0);
	glutSolidTorus(1,10,100,90);
	glPopMatrix();
	glColor3ub(255,191,128);
glPushMatrix();
	glTranslatef(540,494,0);
	glutSolidTorus(7,7,100,90);
	glPopMatrix();*/
	glColor3ub(0,0,0);
	glBegin(GL_LINES);
 		glVertex2i(540,494);
 		glVertex2i(540,490); //nose
  		glVertex2i(531,498);
		glVertex2i(532,499);
 		glVertex2i(532,499);
		glVertex2i(537,498);//eyebrow
  	    glVertex2i(549,498);
		glVertex2i(548,499);
		glVertex2i(548,499);
 		glVertex2i(543,498);//eyebrow
 	glEnd();
//ear right
	glBegin(GL_POLYGON);
	glColor3ub(255,191,128);
	glVertex2i(540-14,494+1);
	glVertex2i(540-14,490+1);
	glVertex2i(538-14,489+1);
	glVertex2i(538-14,495+1);
	glEnd();
	//ear left
	glBegin(GL_POLYGON);
	glColor3ub(255,191,128);
	glVertex2i(554,495);
	glVertex2i(556,496);
	glVertex2i(556,491);
	glVertex2i(554,490);
	glEnd();
	//ear ring right
	glBegin(GL_POLYGON);
	glColor3ub(255,85,90);
	glVertex2i(539-14,492);
	glVertex2i(542-14,485);
	glVertex2i(536-14,485);

	glEnd();
	//ear ring left
   glBegin(GL_POLYGON);
	glColor3ub(255,85,90);
	glVertex2i(551,485);
	glVertex2i(555,492);
	glVertex2i(558,485);
	glEnd();

//hair
	glBegin(GL_POLYGON);
	glColor3ub(0,0,0);
	glVertex2i(525,499);
	glVertex2i(549,509);
	glVertex2i(540,512);
	glVertex2i(528,507);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3ub(0,0,0);
	glVertex2i(540,507);
	glVertex2i(549,509);
	glVertex2i(552,507);
	glVertex2i(555,499);
	glEnd();
	glColor3f(0,0,0);
	// eyes
        glBegin(GL_POLYGON);
 		glVertex2i(533,496);
 		glVertex2i(535,496);
 		glVertex2i(535,494);
 		glVertex2i(533,494);
glEnd();
glBegin(GL_POLYGON);
 		glVertex2i(545,496);
 		glVertex2i(547,496);
     	glVertex2i(547,494);
 		glVertex2i(545,494);
glEnd();
//mouth
glBegin(GL_POLYGON);
 		glColor3ub(150,50,50);
        glVertex2i(534,487);
 		glVertex2i(540,484);
 		glVertex2i(546,487);
 		glVertex2i(540,485);
glEnd();
//shirt
 	glBegin(GL_POLYGON);
 		glColor3ub(160,150,250);
        glVertex2i(529,480);
 		glVertex2i(551,480);
 		glVertex2i(566,469);
 		glVertex2i(561,460);
 		glVertex2i(556,465);
        glVertex2i(556,445);
 		glVertex2i(524,445);
 		glVertex2i(524,465);
 		glVertex2i(519,460);
 		glVertex2i(514,469);
glEnd();
//neck
    glBegin(GL_POLYGON);
        glColor3ub(255,190,128);
        glVertex2i(533,480);
        glVertex2i(547,480);
        glVertex2i(545,471);
        glVertex2i(535,471);
    glEnd();
//hands
 	glBegin(GL_POLYGON);
		glColor3ub(255,191,128);
 		glVertex2i(565,468);
 		glVertex2i(575,453);
 		glVertex2i(567,454);
 		glVertex2i(562,462);
 	glEnd();
  	glBegin(GL_POLYGON);
		glVertex2i(575,453);
 		glVertex2i(556,438);
 		glVertex2i(556,445);
 		glVertex2i(567,454);
 	glEnd();
glBegin(GL_POLYGON);
	 	glVertex2i(515,468);
 		glVertex2i(505,453);
 		glVertex2i(513,454);
 		glVertex2i(518,462);
 	glEnd();
  	glBegin(GL_POLYGON);
		glVertex2i(505,453);
   		glVertex2i(524,438);
   		glVertex2i(524,445);
   		glVertex2i(513,454);
  	glEnd();
// belt
 	glBegin(GL_POLYGON);
		glColor3ub(10,120,130);
 		glVertex2i(556,445);
 		glVertex2i(524,445);
 		glVertex2i(524,440);
 		glVertex2i(556,440);
glEnd();


/*	/// leg
glBegin(GL_POLYGON);
		glColor3ub(255,190,128);
glVertex2i(555,440);
glVertex2i(525,440);
glVertex2i(520,405);
glVertex2i(530,405);
glVertex2i(533,438);
glVertex2i(550,405);
glVertex2i(560,405);
	glEnd();
//skirt
    glBegin(GL_POLYGON);
	    glColor3ub(180,80,90);
		glVertex2i(524,440);
		glVertex2i(556,440);
		glVertex2i(566,410);
		glVertex2i(514,410);
    glEnd();
	//shoe left
	glBegin(GL_POLYGON);
	glColor3ub(180,0,0);
	glVertex2i(530,405);
	glVertex2i(530,396);
	glVertex2i(528,396);
	glVertex2i(528,404);
	glVertex2i(522,396);
	glVertex2i(512,396);
	glVertex2i(520,405);

	glEnd();
	//shoe right
	glBegin(GL_POLYGON);
	glColor3ub(180,0,0);
	glVertex2i(550,405);
	glVertex2i(550,396);
	glVertex2i(552,396);
	glVertex2i(552,404);
	glVertex2i(558,396);
	glVertex2i(568,396);
	glVertex2i(560,405);
	glEnd();*/

}
void face();

void man()
{
	//glColor3ub(0,0,0);
		
	/*glPushMatrix();
	glColor3ub(255,191,128);
	glTranslatef(540-220,495+76,0);
	glutSolidTorus(20,1,5,90);
	glPopMatrix();
	//glColor3ub(255,191,128);
    glPushMatrix();
	glTranslatef(540-220,495+76,0);
	glutSolidTorus(10,1,5,90);
	glPopMatrix();*/
		glColor3ub(0,0,0);
	glBegin(GL_LINES);
 		glVertex2i(540-220,495+76);
 		glVertex2i(540-220,490+76); //nose
  		glVertex2i(531-220,500+76);
 		glVertex2i(537-220,500+76);//eyebrow
  		glVertex2i(543-220,500+76);
 		glVertex2i(549-220,500+76);//eyebrow
 	glEnd();
//ear right
	glBegin(GL_POLYGON);
	glColor3ub(255,191,128);
	glVertex2i(540-14-220,494+1+76);
	glVertex2i(540-14-220,490+1+76);
	glVertex2i(538-14-220,489+1+76);
	glVertex2i(538-14-220,495+1+76);
	glEnd();
	//ear left
	glBegin(GL_POLYGON);
	glColor3ub(255,191,128);
	glVertex2i(554-220,495+76);
	glVertex2i(556-220,496+76);
	glVertex2i(556-220,491+76);
	glVertex2i(554-220,490+76);
	glEnd();
//hair
	glBegin(GL_POLYGON);
	  glColor3ub(0,0,0);
	  glVertex2i(527-220,503+76);
	  glVertex2i(553-220,503+76);
	  glVertex2i(547-220,509+76);
	  glVertex2i(533-220,509+76);
	glEnd();


	// eyes
	glColor3f(0,0,0);
 	glBegin(GL_POLYGON);
 		glVertex2i(533-220,498+76);
 		glVertex2i(535-220,498+76);
 		glVertex2i(535-220,496+76);
 		glVertex2i(533-220,496+76);
glEnd();
glBegin(GL_POLYGON);
 		glVertex2i(545-220,498+76);
 		glVertex2i(547-220,498+76);
 		glVertex2i(547-220,496+76);
 		glVertex2i(545-220,496+76);
glEnd();
 	// mouth
glBegin(GL_POLYGON);
 		glVertex2i(535-220,487+76);
 		glVertex2i(540-220,485+76);
 		glVertex2i(545-220,487+76);
 		glVertex2i(540-220,487+76);
glEnd();
//beard
glBegin(GL_POLYGON);
    glColor3ub(0,0,0);
    glVertex2i(538-220,480+76);
	glVertex2i(542-220,480+76);
	glVertex2i(542-220,484+76);
	glVertex2i(538-220,484+76);
glEnd();
//shirt
 	glBegin(GL_POLYGON);
 		glColor3ub(55,50,70);
	    glVertex2i(529-220,480+76);
 		glVertex2i(551-220,480+76);
 		glVertex2i(566-220,469+76);
 		glVertex2i(561-220,461+76);
 		glVertex2i(556-220,465+76);
        glVertex2i(556-220,445+76);
 		glVertex2i(524-220,445+76);
 		glVertex2i(524-220,465+76);
 		glVertex2i(519-220,460+76);
 		glVertex2i(514-220,469+76);
glEnd();
//hands
 	glBegin(GL_POLYGON);
		glColor3ub(255,191,128);
 		glVertex2i(565-220,468+76);
 		glVertex2i(575-220,453+76);
 		glVertex2i(567-220,454+76);
 		glVertex2i(562-220,462+76);
 	glEnd();
  	glBegin(GL_POLYGON);
		glVertex2i(575-220,453+76);
 		glVertex2i(556-220,438+76);
 		glVertex2i(556-220,445+76);
 		glVertex2i(567-220,454+76);
 	glEnd();
glBegin(GL_POLYGON);
	 	glVertex2i(515-220,468+76);
 		glVertex2i(505-220,453+76);
 		glVertex2i(513-220,454+76);
 		glVertex2i(518-220,462+76);
 	glEnd();
  	glBegin(GL_POLYGON);
		glVertex2i(505-220,453+76);
   		glVertex2i(524-220,438+76);
   		glVertex2i(524-220,445+76);
   		glVertex2i(513-220,454+76);
  	glEnd();
// belt
 	glBegin(GL_POLYGON);
		glColor3ub(150,12,30);
 		glVertex2i(556-220,445+76);
 		glVertex2i(524-220,445+76);
 		glVertex2i(524-220,440+76);
		glVertex2i(524-220,440+76);

 		glVertex2i(556-220,440+76);
glEnd();
// collar
 	glBegin(GL_POLYGON);
		glColor3ub(200,140,110+76);
 		glVertex2i(529-220,480+76);
 		glVertex2i(551-220,480+76);
 		glVertex2i(546-220,470+76);
 		glVertex2i(534-220,470+76);
glEnd();

 	glBegin(GL_TRIANGLES);
		glColor3ub(20,140,110);
 		glVertex2i(540-220,477+76);
  		glVertex2i(545-220,470+76);
 		glVertex2i(535-220,470+76);
glEnd();

// buttons
	glColor3ub(0,0,0);
	glPushMatrix();
	glTranslatef(540-220,465+76,0);
	glutSolidTorus(1,1,100,90);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(540-220,458+76,0);
	glutSolidTorus(1,1,100,90);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(540-220,451+76,0);
	glutSolidTorus(1,1,100,90);
	glPopMatrix();

/*	/// pant
glBegin(GL_POLYGON);
		glColor3ub(80,80,230);
glVertex2i(555-220,440+76);
glVertex2i(525-220,440+76);
glVertex2i(520-220,405+76);
glVertex2i(530-220,405+76);
glVertex2i(533-220,438+76);
glVertex2i(550-220,405+76);
glVertex2i(560-220,405+76);
	glEnd();
		//shoe left
	glBegin(GL_POLYGON);
	glColor3ub(100,10,10);
	glVertex2i(530-220,405+76);
	glVertex2i(530-220,396+76);
	glVertex2i(512-220,396+76);
	glVertex2i(520-220,405+76);

	glEnd();
	//shoe right
	glBegin(GL_POLYGON);
	glColor3ub(100,10,10);
	glVertex2i(550-220,405+76);
	glVertex2i(550-220,396+76);
	glVertex2i(568-220,396+76);
	glVertex2i(560-220,405+76);
	glEnd();*/

}

void face(){
	glColor3ub(255,191,128);
	int k=0;
	float an;
	glBegin(GL_POLYGON);
	for(k=0;k<100;k++){
		an=k*2*(3.14/100);
		glVertex2f(100+(sin(an)*15),y+(cos(an)*15));
	}
	glEnd();
	}

void encryption()
{
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
glMatrixMode(GL_MODELVIEW);
//glPushMatrix();
// glColor3f(0.25,0.15,0.36);
glColor3f(1.0f,0,0);
output(325,650,"RSA",2);

glColor3f(1.0f,1.0f,1.0f);
output(300,125,"Channel",2);
//glPopMatrix();
glColor3f(1.0f,1.0f,1.0f);
output(180,300,"Encryption",2);

glColor3f(1.0f,1.0f,1.0f);
output(395,300,"Decryption",2);

//glColor3f(1.0f,1.0f,1.0f);
glPushMatrix();
glTranslatef(-30,200,0);
output(90,455,"Sender(Bob)",2);
//glTranslated(10,0,0);
//computer();
glPopMatrix();

//glColor3f(1.0f,1.0f,1.0f);
glPushMatrix();
output(550,645,"Receiver(Alice)",2);
//glTranslated(-15,10,0);
//computer_dest();
glPopMatrix();

glPushMatrix();//face man
glTranslated(-10,613,0);
face();
glPopMatrix();

glPushMatrix();//face woman
glTranslated(470,618,0);
face();
glPopMatrix();

glPushMatrix();
glTranslated(-230,50,0);
man();
glPopMatrix();
glPushMatrix();
glTranslated(30,130,0);
woman();
glPopMatrix();



glColor3f(1.0f,1.0f,1.0f);
/*glBegin(GL_LINE_STRIP);//channel
glVertex2i(170,500);
glVertex2i(170,150);
glVertex2i(480,150);
glVertex2i(480,500);
glEnd();
glBegin(GL_LINE_STRIP);
glVertex2i(10,500);
glVertex2i(10,20);
glVertex2i(650,20);
glVertex2i(650,500);
glEnd();*/
glBegin(GL_LINES);
glVertex2i(170,305);
glVertex2i(180,305);
glVertex2i(480,305);
glVertex2i(470,305);
glEnd();
/*glBegin(GL_LINE_STRIP);
glVertex2i(170,500);
glVertex2i(170,150);
glVertex2i(480,150);
glVertex2i(480,500);
glVertex2i(650,500);
glVertex2i(650,20);
glVertex2i(10,20);
glVertex2i(10,500);
glEnd();*/
glColor3f(1,0,0);
glBegin(GL_POLYGON);
glVertex2i(10,500);
glVertex2i(10,20);
glVertex2i(650,20);
glVertex2i(650,500);
glVertex2i(480,500);
glVertex2i(480,150);
glVertex2i(170,150);
glVertex2i(170,500);
glEnd();


if(phy_header_angle1!=100)
{
glPushMatrix();
glTranslatef(0,-phy_header_angle1,0);
glPushMatrix();
glTranslatef(0,-arrow_angle,0);
glTranslatef(0,150,0);
message_data();
glPopMatrix();
glPushMatrix();
glTranslatef(phy_header_angle,0,0);
glTranslatef(-100,0,0);
message_key();
glPopMatrix();
glPopMatrix();
}
glPushMatrix();
glTranslatef(movement_angle1,0,0);
if(phy_header_angle1==100)
{
glPushMatrix();
if(movement_angle1>=420)
{
// glRotatef(180,0,1,0);
glTranslatef(0,rev_analog_sig_angle,0);
}
glTranslatef(0,-analog_sig_angle,0);
if(rev_analog_sig_angle!=100)
cipher();
glPopMatrix();
}
glPopMatrix();
glPushMatrix();
glTranslatef(movement_angle1,0,0);
if(phy_header_angle1==100)
{
glPushMatrix();
glScalef(50,30,.5);
glTranslatef(2.5,2.5,0);
glutWireCube(2);
glPopMatrix();
}
glPopMatrix();
if(rev_analog_sig_angle==100)
{
glPushMatrix();
glTranslatef(450,rev_phy_header_angle1,0);
glPushMatrix();
//glTranslatef(0,rev_arrow_angle,0);
//glTranslatef(0,0,0);
message_data();
glPopMatrix();
glPushMatrix();
glTranslatef(rev_phy_header_angle,0,0);
glTranslatef(-10,0,0);
if(rev_phy_header_angle<200)
message_key();
glPopMatrix();
glPopMatrix();
}
glColor3f(1.0f,1.0f,1.0f);
glPushMatrix();
glTranslatef(450,0,0);
glScalef(70,40,.5);
glTranslatef(1.5,7,0);
//glutWireCube(2);//right layer
glPopMatrix();//delay1();
animation_encryp();

glFlush();
glutSwapBuffers();
}




void myinit()
{
glColor3f(1.0,0.0,0.0);
glPointSize(1.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0.0,700.0,0.0,700.0);
}

void display()
{
glClearColor(.2,.2,.2,0.0);
glClear(GL_COLOR_BUFFER_BIT);
front_page();
glFlush();
glutSwapBuffers();
}


void key (unsigned char key, int x, int y)
{
switch(key) {

case 'S' :
case 's' :glutDisplayFunc(encryption);
	break;
   case 'q':  
   case 'Q':
          exit(0);
 }
 glutPostRedisplay();
}

static void menu(int mode)
{
switch (mode)
{
case FRONTPAGE:glutDisplayFunc(front_page);
break;
case ENCRYPTION:glutDisplayFunc(encryption);
break;
case EXIT: exit(0);
}
glutPostRedisplay();
glFlush();
}

int main(int argc, char** argv)
{
rsa();
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
glutInitWindowSize(1000,700);
glutInitWindowPosition(0,0);
glutCreateWindow("ENCRYPTION");

glutKeyboardFunc(key);

myinit();
glutDisplayFunc(display);
glutCreateMenu(menu);
glutAddMenuEntry("Front Page", FRONTPAGE);
glutAddMenuEntry("Encryption",ENCRYPTION);
glutAddMenuEntry("Exit", EXIT);
glutAttachMenu(GLUT_RIGHT_BUTTON);

glutMainLoop();
return 0;
//kavyashreeed;
}
