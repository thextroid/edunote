
#include <stdio.h>
#include <string.h>
char Mat[25][20][80], dir[100];
int size[20], cols;
void chars( char ch, int length ) {
int i;
for( i=0; i<length; i++ )
putchar( ch );
}
void print( char ch1, char ch2 ) {
int i;
putchar( ch1 );
for( i=0; i<cols; i++ ){
if( i )
putchar( ch2 );
chars( '-', size[i]+2 );
}
printf( "%c\n", ch1 );
}
void printline( int row ) {
int le, ri, wrd, i;
putchar( '|' );
for( i=0; i<cols; i++ ){
if( i ) putchar( '|' );
wrd = strlen( Mat[row][i] );
switch( dir[i] ) {
case '<':le = 1; ri = size[i]-wrd+1; break;
case '>':le = size[i]-wrd+1; ri = 1; break;
case '=':le = (size[i]-wrd)/2 +1; ri = size[i]+2 - wrd-le;
break;
}
chars( ' ', le );
printf( "%s", Mat[row][i] );
chars( ' ', ri );
}
printf( "%c\n", '|' );
}
int main() {
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
char line[100], *cad;
int col, row, sz, i, j;
gets( line );
while( 1 ) {
if( line[0]=='*' )
break;
strcpy( dir, line );
cols = strlen( line );
for( i=0; i<cols; i++ )
size[i] = 0;
row = 0;
while( 1 ) {
gets( line );
if( line[0]=='<' || line[0]=='>' || line[0]=='='
|| line[0]=='*' )
break;
for( cad = strtok(line,"&"), col=0;
cad!=NULL; cad = strtok(NULL,"&" ), col++ ) {
strcpy( Mat[row][col], cad );
sz = strlen( cad );
if( sz > size[col] )
size[col] = sz;
}
row++;
}
print( '@', '-' );
printline( 0);
print( '|', '+' );
for( j=1; j<row; j++ ) {
printline( j );
}
print( '@', '-' );
}
return 0;
}