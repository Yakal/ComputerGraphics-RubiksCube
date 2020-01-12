//  Rubic's Small Cube HW#2
//  Furkan Yakal 59943

#define GL_SILENCE_DEPRECATION
#include "Angel.h"

typedef vec4  color4;
typedef vec4  point4;
//-------------------------------------------------------------------------------------------
const float edgeLength = 0.5;  //edge length of each small cube
const float difference = 0.01; //distance between each cube

const float originX=0.0;
const float originY=0.0;       //initial coordinates
const float originZ=0.0;

GLfloat initialXAngle=30.0;
GLfloat initialYAngle=-45.0;  //initial view angles
GLfloat initialZAngle=0.0;

int randomNumber=0; //for determining the number of random rotations set from 'r' or 'R' key

//8 different cubes with coordinates, coordinates of the corner points
//|1|2|  From up                     |5|6| From bottom
//|0|3|                              |4|7|

point4 cube0[8] = {
    point4( originX-edgeLength-difference, originY+edgeLength+difference,  originZ+edgeLength+difference, 1.0 ),
    point4( originX-edgeLength-difference,  originY+difference,  originZ+edgeLength+difference, 1.0 ),
    point4(  originX-difference,  originY+difference,  originZ+edgeLength+difference, 1.0 ),
    point4(  originX-difference, originY+edgeLength+difference,  originZ+edgeLength+difference, 1.0 ),
    point4( originX-edgeLength-difference, originY+edgeLength+difference, originZ+difference, 1.0 ),
    point4( originX-edgeLength-difference,  originY+difference, originZ+difference, 1.0 ),
    point4(  originX-difference,  originY+difference, originZ+difference, 1.0 ),
    point4(  originX-difference, originY+edgeLength+difference, originZ+difference, 1.0 )
};
point4 cube1[8] = {
    point4(  originX-edgeLength-difference,  originY+edgeLength+difference, originZ-difference, 1.0 ),
    point4(  originX-edgeLength-difference,  originY+difference, originZ-difference, 1.0 ),
    point4(  originX-difference,  originY+difference, originZ-difference, 1.0 ),
    point4(  originX-difference,  originY+edgeLength+difference, originZ-difference, 1.0 ),
    point4(  originX-edgeLength-difference,  originY+edgeLength+difference, originZ-edgeLength-difference, 1.0 ),
    point4(  originX-edgeLength-difference,  originY+difference, originZ-edgeLength-difference, 1.0 ),
    point4(  originX-difference,  originY+difference, originZ-edgeLength-difference, 1.0 ),
    point4(  originX-difference,  originY+edgeLength+difference, originZ-edgeLength-difference, 1.0 )
};
point4 cube2[8] = {
    point4(  originX+difference,  originY+edgeLength+difference, originZ-difference, 1.0 ),
    point4(  originX+difference,  originY+difference, originZ-difference, 1.0 ),
    point4(  originX+edgeLength+difference,  originY+difference, originZ-difference, 1.0 ),
    point4(  originX+edgeLength+difference,  originY+edgeLength+difference, originZ-difference, 1.0 ),
    point4(  originX+difference,  originY+edgeLength+difference, originZ-edgeLength-difference, 1.0 ),
    point4(  originX+difference,  originY+difference, originZ-edgeLength-difference, 1.0 ),
    point4(  originX+edgeLength+difference,  originY+difference, originZ-edgeLength-difference, 1.0 ),
    point4(  originX+edgeLength+difference,  originY+edgeLength+difference, originZ-edgeLength-difference, 1.0 )
};
point4 cube3[8] = {
    point4(  originX+difference,  originY+edgeLength+difference, originZ+edgeLength+difference, 1.0 ),
    point4(  originX+difference,  originY+difference, originZ+edgeLength+difference, 1.0 ),
    point4(  originX+edgeLength+difference,  originY+difference, originZ+edgeLength+difference, 1.0 ),
    point4(  originX+edgeLength+difference,  originY+edgeLength+difference, originZ+edgeLength+difference, 1.0 ),
    point4(  originX+difference,  originY+edgeLength+difference, originZ+difference, 1.0 ),
    point4(  originX+difference,  originY+difference, originZ+difference, 1.0 ),
    point4(  originX+edgeLength+difference,  originY+difference, originZ+difference, 1.0 ),
    point4(  originX+edgeLength+difference,  originY+edgeLength+difference, originZ+difference, 1.0 )
};
point4 cube4[8] = {
    point4(  originX-edgeLength-difference,  originY-difference, originZ+edgeLength+difference, 1.0 ),
    point4(  originX-edgeLength-difference,  originY-edgeLength-difference, originZ+edgeLength+difference, 1.0 ),
    point4(  originX-difference,  originY-edgeLength-difference, originZ+edgeLength+difference, 1.0 ),
    point4(  originX-difference,  originY-difference, originZ+edgeLength+difference, 1.0 ),
    point4(  originX-edgeLength-difference,  originY-difference, originZ+difference, 1.0 ),
    point4(  originX-edgeLength-difference,  originY-edgeLength-difference, originZ+difference, 1.0 ),
    point4(  originX-difference,  originY-edgeLength-difference, originZ+difference, 1.0 ),
    point4(  originX-difference,  originY-difference, originZ+difference, 1.0 )
};
point4 cube5[8] = {
    point4(  originX-edgeLength-difference,  originY-difference, originZ-difference, 1.0 ),
    point4(  originX-edgeLength-difference,  originY-edgeLength-difference, originZ-difference, 1.0 ),
    point4(  originX-difference,  originY-edgeLength-difference, originZ-difference, 1.0 ),
    point4(  originX-difference,  originY-difference, originZ-difference, 1.0 ),
    point4(  originX-edgeLength-difference,  originY-difference, originZ-edgeLength-difference, 1.0 ),
    point4(  originX-edgeLength-difference,  originY-edgeLength-difference, originZ-edgeLength-difference, 1.0 ),
    point4(  originX-difference,  originY-edgeLength-difference, originZ-edgeLength-difference, 1.0 ),
    point4(  originX-difference,  originY-difference, originZ-edgeLength-difference, 1.0 )
};
point4 cube6[8] = {
    point4(  originX+difference,  originY-difference, originZ-difference, 1.0 ),
    point4(  originX+difference,  originY-edgeLength-difference, originZ-difference, 1.0 ),
    point4(  originX+edgeLength+difference,  originY-edgeLength-difference, originZ-difference, 1.0 ),
    point4(  originX+edgeLength+difference,  originY-difference, originZ-difference, 1.0 ),
    point4(  originX+difference,  originY-difference, originZ-edgeLength-difference, 1.0 ),
    point4(  originX+difference,  originY-edgeLength-difference, originZ-edgeLength-difference, 1.0 ),
    point4(  originX+edgeLength+difference,  originY-edgeLength-difference, originZ-edgeLength-difference, 1.0 ),
    point4(  originX+edgeLength+difference,  originY-difference, originZ-edgeLength-difference, 1.0 )
};
point4 cube7[8] = {
    point4(  originX+difference,  originY-difference, originZ+edgeLength+difference, 1.0 ),
    point4(  originX+difference,  originY-edgeLength-difference, originZ+edgeLength+difference, 1.0 ),
    point4(  originX+edgeLength+difference,  originY-edgeLength-difference, originZ+edgeLength+difference, 1.0 ),
    point4(  originX+edgeLength+difference,  originY-difference, originZ+edgeLength+difference, 1.0 ),
    point4(  originX+difference,  originY-difference, originZ+difference, 1.0 ),
    point4(  originX+difference,  originY-edgeLength-difference, originZ+difference, 1.0 ),
    point4(  originX+edgeLength+difference,  originY-edgeLength-difference, originZ+difference, 1.0 ),
    point4(  originX+edgeLength+difference,  originY-difference, originZ+difference, 1.0 )
};

point4 cube[8][8]={
{cube0[0],cube0[1],cube0[2],cube0[3],cube0[4],cube0[5],cube0[6],cube0[7]},
{cube1[0],cube1[1],cube1[2],cube1[3],cube1[4],cube1[5],cube1[6],cube1[7]},
{cube2[0],cube2[1],cube2[2],cube2[3],cube2[4],cube2[5],cube2[6],cube2[7]},
{cube3[0],cube3[1],cube3[2],cube3[3],cube3[4],cube3[5],cube3[6],cube3[7]},
{cube4[0],cube4[1],cube4[2],cube4[3],cube4[4],cube4[5],cube4[6],cube4[7]},
{cube5[0],cube5[1],cube5[2],cube5[3],cube5[4],cube5[5],cube5[6],cube5[7]},
{cube6[0],cube6[1],cube6[2],cube6[3],cube6[4],cube6[5],cube6[6],cube6[7]},
{cube7[0],cube7[1],cube7[2],cube7[3],cube7[4],cube7[5],cube7[6],cube7[7]}
};

//Cubes positioning from each side
//|1|2|  From up      |5|6| From bottom    |0|3| From front    |2|1| From back    |3|2| From back   |1|0| From left
//|0|3|               |4|7|                |4|7|               |6|5|              |7|6|             |5|4|

//6 different faces, each holds the initial positions of the cubes
//placing into arrays: starting from the bottom-left-corner follow clockwise
int up[4] = {0,1,2,3};
int bottom[4] = {4,5,6,7};

int front[4] = {4,0,3,7};
int back[4] = {6,2,1,5};

int right[4] = {7,3,2,6};
int left[4] = {5,1,0,4};
//-------------------------
const int NumVertices = 288;//36*8 //8 cubes// 1 cube has 36 vertices (6 faces)(2 triangles/face)(3 vertices/triangle)

point4 points[9][NumVertices];
color4 colors[9][NumVertices];

// RGBA olors
color4 vertex_colors[7] = {
    color4( 1.0, 0.0, 0.0, 1.0 ),  // red
    color4( 1.0, 0.0, 1.0, 1.0 ),  // magenta
    color4( 1.0, 1.0, 0.0, 1.0 ),  // yellow
    color4( 0.0, 1.0, 0.0, 1.0 ),  // green
    color4( 0.0, 0.0, 1.0, 1.0 ),  // blue
    color4( 1.0, 0.5, 0.0, 1.0 ),  // orange
    color4( 0.0, 0.0, 0.0, 0.0)    // black
};

// Array of rotation angles (in degrees) for each coordinate axis
enum { Xaxis = 0, Yaxis = 1, Zaxis = 2, NumAxes = 3 };
int Axis = Xaxis;
//----------------------------------------------------------------------------

// quad generates two triangles for each face and assigns colors to the vertices
int Index = 0;
void
quad( int a, int b, int c, int d, int color, int i )
{
    // Initialize colors
    int colorIdentify = 6; //for colouring inner parts of the subcubes to black
    if(color==0 && (i==0 || i==3 || i==4 || i==7)) colorIdentify=0;
    else if(color==1 && (i==2 || i==3 || i==6 || i==7)) colorIdentify=1;
    else if(color==2 && (i==1 || i==2 || i==5 || i==6)) colorIdentify=2;
    else if(color==3 && (i==0 || i==1 || i==4 || i==5)) colorIdentify=3;
    else if(color==4 && (i==0 || i==1 || i==2 || i==3)) colorIdentify=4;
    else if(color==5 && (i==4 || i==5 || i==6 || i==7)) colorIdentify=5;
        
    colors[i][Index] = vertex_colors[colorIdentify]; points[i][Index]=cube[i][a]; Index++;
    colors[i][Index] = vertex_colors[colorIdentify]; points[i][Index]=cube[i][b]; Index++;
    colors[i][Index] = vertex_colors[colorIdentify]; points[i][Index]=cube[i][c]; Index++;
    colors[i][Index] = vertex_colors[colorIdentify]; points[i][Index]=cube[i][a]; Index++;
    colors[i][Index] = vertex_colors[colorIdentify]; points[i][Index]=cube[i][c]; Index++;
    colors[i][Index] = vertex_colors[colorIdentify]; points[i][Index]=cube[i][d]; Index++;
    
    if(Index==36)Index=0;
}
//----------------------------------------------------------------------------
// generate 12 triangles: 36 vertices and 36 colors for each cube.
void
rubicCube()
{
    for (int i=0; i<8 ; i++){
        quad( 0, 1, 2, 3, 0, i );
        quad( 3, 2, 6, 7, 1, i );
        quad( 7, 6, 5, 4, 2, i );
        quad( 4, 5, 1, 0, 3, i );
        quad( 4, 0, 3, 7, 4, i );
        quad( 5, 1, 2, 6, 5, i );
    }
    int index=0;
    for(int i=0; i<8; i++){
        for(int j=0; j<36; j++){
            points[8][index]=points[i][j];
            colors[8][index]=colors[i][j];
            index+=1;
        }
    }
}
//-----------------------------------
//for rotating which side with which angle, can be determined with the left or right button of the mouse
bool upRotationPosAngle = false;
bool upRotationNegAngle = false;
bool rightRotationPosAngle = false;
bool rightRotationNegAngle = false;
bool frontRotationPosAngle = false;
bool frontRotationNegAngle = false;

bool rotateRubicCubeUp= false;
bool rotateRubicCubeDown = false;
bool rotateRubicCubeRight = false;
bool rotateRubicCubeLeft = false;

bool preventMultipleActions = false;

bool randomButtonPressed = false; //for random configuration of rubic's cube use key 'r' or 'R'
//----------------------------------------------------------------------------
// OpenGL initialization
// Model-view and projection matrices uniform location
//there are 9 modelview matrices 8 for each subcube, and 1 for the whole
GLuint  ModelView, Projection;
GLuint vao[9];
GLuint vPosition;
GLuint vColor;
mat4 model_view[9];
void init()
{
    std::cout << " Rubic's Small Cube " <<std::endl;
    std::cout << " For instructions please press 'h' " <<std::endl;
    rubicCube();
    
    GLuint buffer;
    // Create vertex array objects
    glGenVertexArrays( 9, vao );
    // Load shaders and use the resulting shader program
    GLuint program=InitShader( "vshader.glsl", "fshader.glsl" );
    
    for(int i=0; i<9; i++){
        glBindVertexArray( vao[i] );
        glGenBuffers( 1, &buffer );
        glBindBuffer( GL_ARRAY_BUFFER, buffer );
        glBufferData( GL_ARRAY_BUFFER, sizeof(points[i]) + sizeof(colors[i]), NULL, GL_STATIC_DRAW );
        glBufferSubData( GL_ARRAY_BUFFER, 0, sizeof(points[i]), points[i] );
        glBufferSubData( GL_ARRAY_BUFFER, sizeof(points[i]), sizeof(colors[i]), colors[i] );
        
        vPosition = glGetAttribLocation( program, "vPosition" );
        glEnableVertexAttribArray( vPosition );
        glVertexAttribPointer( vPosition, 4, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0) );
        
        vColor = glGetAttribLocation( program, "vColor" );
        glEnableVertexAttribArray( vColor );
        glVertexAttribPointer( vColor, 4, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(sizeof(points[i])) );
        model_view[i] = identity();
    }
    // Retrieve transformation uniform variable locations
    ModelView = glGetUniformLocation( program, "ModelView" );
    Projection = glGetUniformLocation( program, "Projection" );
    
    // Set current program object
    glUseProgram( program );
    
    // Enable hiddden surface removal
    glEnable( GL_DEPTH_TEST );
    
    // Set state variable "clear color" to clear buffer with.
    glClearColor( 0.0, 0.0, 0.0, 0.0 );
}

//----------------------------------------------------------------------------
//display function

//applies the rotations
//rotation in 3 different axis(right, front and up). Each axis movement in 2 different angles

//rotation of rubic cube. With rubic cube rotations all faces can be observed.
//can rotate rubic cube 90 degrees in Y
//or 180 degrees in X

bool initial = true;
void
display( void )
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    for(int i=0; i<8 ;i++){
        glBindVertexArray(vao[i]);
    //-----------------------
        if(rightRotationPosAngle && (i==right[0] || i == right[1] || i== right[2] || i== right[3])){
            model_view[i]= RotateX(initialXAngle) * RotateY(initialYAngle) * RotateX(1.0)* RotateY(-initialYAngle) * RotateX(-initialXAngle) *  model_view[i];
        }
        else if(rightRotationNegAngle && (i==right[0] || i == right[1] || i== right[2] || i== right[3])){
            model_view[i]= RotateX(initialXAngle) * RotateY(initialYAngle) * RotateX(-1.0)* RotateY(-initialYAngle) * RotateX(-initialXAngle) *  model_view[i];
        }
    //-----------------------
        else if(upRotationPosAngle  && (i==up[0] || i == up[1] || i== up[2] || i== up[3])){
           model_view[i]= RotateX(initialXAngle) * RotateY(initialYAngle) * RotateY(1.0)* RotateY(-initialYAngle) * RotateX(-initialXAngle) *  model_view[i];
        }
        else if(upRotationNegAngle && (i==up[0] || i == up[1] || i== up[2] || i== up[3])){
           model_view[i]= RotateX(initialXAngle) * RotateY(initialYAngle) * RotateY(-1.0)* RotateY(-initialYAngle) * RotateX(-initialXAngle) *  model_view[i];
        }
     //-----------------------
        else if(frontRotationPosAngle  && (i==front[0] || i == front[1] || i== front[2] || i== front[3])){
            model_view[i]= RotateX(initialXAngle) * RotateY(initialYAngle) * RotateZ(1.0)* RotateY(-initialYAngle) * RotateX(-initialXAngle) *  model_view[i];
        }
        else if(frontRotationNegAngle && (i==front[0] || i == front[1] || i== front[2] || i== front[3])){
           model_view[i]= RotateX(initialXAngle) * RotateY(initialYAngle) * RotateZ(-1.0)* RotateY(-initialYAngle) * RotateX(-initialXAngle) *  model_view[i];
        }
     //-----------------------
        else if(rotateRubicCubeDown){
            model_view[i] =  RotateX(-1.0) *  model_view[i];
        }
        else if(rotateRubicCubeUp){
            model_view[i] = RotateX(1.0) *  model_view[i];
        }
        else if(rotateRubicCubeRight){
           model_view[i]= RotateX(initialXAngle) * RotateY(initialYAngle) * RotateY(-1.0)* RotateY(-initialYAngle) * RotateX(-initialXAngle) *  model_view[i];
        }
        else if(rotateRubicCubeLeft){
           model_view[i]= RotateX(initialXAngle) * RotateY(initialYAngle) * RotateY(1.0)* RotateY(-initialYAngle) * RotateX(-initialXAngle) *  model_view[i];
        }
    //-----------------------
        else if(initial){ //initial looking of the cube used only at the beginning then it is set false
            model_view[i] =RotateX( initialXAngle ) * RotateY( initialYAngle ) * RotateZ(initialZAngle)*model_view[i];
        }
        glUniformMatrix4fv( ModelView, 1, GL_TRUE, model_view[i] );
        glDrawArrays( GL_TRIANGLES, 0, NumVertices );
    }
    initial=false;
    glutSwapBuffers();
    
}

//---------------------------------------------------------------------
// reshape
void reshape( int w, int h )
{
    glViewport( 0, 0, w, h );
    // Set projection matrix
    mat4  projection;
    if (w <= h)
        projection = Ortho(-1.0, 1.0, -1.0 * (GLfloat) h / (GLfloat) w,
                           1.0 * (GLfloat) h / (GLfloat) w, -1.0, 1.0);
    else  projection = Ortho(-1.0* (GLfloat) w / (GLfloat) h, 1.0 *
                             (GLfloat) w / (GLfloat) h, -1.0, 1.0, -1.0, 1.0);
    glUniformMatrix4fv( Projection, 1, GL_TRUE, projection );
}
//----------------------------------------------------------------------------
//updates each face with cube indices according to appropriate rotation.
void updateCubeArrays (){
    int dummyFront [4] = {front[0] , front[1], front[2] , front[3]};
    int dummyBack [4] = {back[0] , back[1] , back[2] , back[3]};
    int dummyRight [4] = {right[0] , right[1] , right[2] , right[3]};
    int dummyLeft [4] = {left[0] , left[1] , left[2] , left[3]};
    int dummyUp [4] = {up[0] , up[1] , up[2] , up[3]};
    int dummyBottom [4] = {bottom[0] , bottom [1] , bottom[2] , bottom[3]};
    
    if(rotateRubicCubeRight){
        front[0] = dummyRight[0];
        front[1] = dummyRight[1];
        front[2] = dummyRight[2];
        front[3] = dummyRight[3];
        
        right[0] = dummyBack[0];
        right[1] = dummyBack[1];
        right[2] = dummyBack[2];
        right[3] = dummyBack[3];
        
        left[0] = dummyFront[0];
        left[1] = dummyFront[1];
        left[2] = dummyFront[2];
        left[3] = dummyFront[3];
        
        back[0] = dummyLeft[0];
        back[1] = dummyLeft[1];
        back[2] = dummyLeft[2];
        back[3] = dummyLeft[3];
        
        bottom[0] = dummyBottom[3];
        bottom[1] = dummyBottom[0];
        bottom[2] =dummyBottom[1];
        bottom[3] = dummyBottom[2];
        
        up[0] = dummyUp[3];
        up[1] = dummyUp[0];
        up[2] = dummyUp[1];
        up[3] = dummyUp[2];
    }
    else if(rotateRubicCubeLeft){
        front[0] = dummyLeft[0];
        front[1] = dummyLeft[1];
        front[2] = dummyLeft[2];
        front[3] = dummyLeft[3];
        
        right[0]= dummyFront[0];
        right[1]= dummyFront[1];
        right[2]= dummyFront[2];
        right[3]= dummyFront[3];
        
        left[0] = dummyBack[0];
        left[1] = dummyBack[1];
        left[2] = dummyBack[2];
        left[3] =dummyBack[3];
    
        back[0] = dummyRight[0];
        back[1] = dummyRight[1];
        back[2] = dummyRight[2];
        back[3] = dummyRight[3];
        
        bottom[0] = dummyBottom[1];
        bottom[1] = dummyBottom[2];
        bottom[2] = dummyBottom[3];
        bottom[3] = dummyBottom[0];
        
        up[0] = dummyUp[1];
        up[1] = dummyUp[2];
        up[2] =dummyUp[3];
        up[3] = dummyUp[0];
        
    }
    else if(rotateRubicCubeUp || rotateRubicCubeDown){
        right[0] = dummyBack[2];
        right[1] = dummyBack[3];
        right[2] = dummyBack[0];
        right[3] = dummyBack[1];
        
        left[0] = dummyFront[2];
        left[1] = dummyFront[3];
        left[2] = dummyFront[0];
        left[3] = dummyFront[1];
        
        front[0] = dummyLeft[2];
        front[1] = dummyLeft[3];
        front[2] = dummyLeft[0];
        front[3] = dummyLeft[1];
        
        back[0] = dummyRight[2];
        back[1] = dummyRight[3];
        back[2] = dummyRight[0];
        back[3] = dummyRight[1];
        
        bottom[0] = dummyUp[0];
        bottom[1] = dummyUp[3];
        bottom[2] = dummyUp[2];
        bottom[3] = dummyUp[1];
        
        up[0] = dummyBottom[0];
        up[1] = dummyBottom[3];
        up[2] = dummyBottom[2];
        up[3] = dummyBottom[1];
    }
    else if(upRotationNegAngle){
        right[1] = dummyBack[1];
        right[2] = dummyBack[2];
        
        left[1] = dummyFront[1];
        left[2] = dummyFront[2];
        
        front[1] = dummyRight[1];
        front[2] = dummyRight[2];
       
        back[1] = dummyLeft[1];
        back[2] = dummyLeft[2];
        
        up[0] = dummyUp[3];
        up[1] = dummyUp[0];
        up[2] = dummyUp[1];
        up[3] = dummyUp[2];
    }
    else if(upRotationPosAngle){
        right[1]= dummyFront[1];
        right[2]= dummyFront[2];
    
        left[1] = dummyBack[1];
        left[2] = dummyBack[2];
    
        front[1] = dummyLeft[1];
        front[2] = dummyLeft[2];
     
        back[1] = dummyRight[1];
        back[2] = dummyRight[2];
  
        up[0] = dummyUp[1];
        up[1] = dummyUp[2];
        up[2] =dummyUp[3];
        up[3] = dummyUp[0];
    }
    else if(rightRotationNegAngle){
        right[0] = dummyRight[3];
        right[1] = dummyRight[0];
        right[2] = dummyRight[1];
        right[3] = dummyRight[2];
        
        front[2] = dummyBottom[3];
        front[3] = dummyBottom[2];
        
        back[0] = dummyUp[2];
        back[1] = dummyUp[3];
        
        bottom[2] = dummyBack[1];
        bottom[3] = dummyBack[0];
    
        up[2] = dummyFront[2];
        up[3] = dummyFront[3];
    }
    else if(rightRotationPosAngle){
        right[0] = dummyRight[1];
        right[1] = dummyRight[2];
        right[2] = dummyRight[3];
        right[3] = dummyRight[0];
        
        front[2] = dummyUp[2];
        front[3] = dummyUp[3];
        
        back[0] = dummyBottom[3];
        back[1] = dummyBottom[2];
     
        bottom[2] = dummyFront[3];
        bottom[3] = dummyFront[2];
        
        up[2] = dummyBack[0];
        up[3] = dummyBack[1];
    }
    else if(frontRotationNegAngle){
        right[0]= dummyUp[3];
        right[1]= dummyUp[0];
 
        left[2] = dummyBottom[0];
        left[3] =dummyBottom[3];
        
        front[0] = dummyFront[3];
        front[1] = dummyFront[0];
        front[2] = dummyFront[1];
        front[3] = dummyFront[2];
        
        bottom[0] = dummyRight[0];
        bottom[3] = dummyRight[1];
        
        up[0] = dummyLeft[3];
        up[3] = dummyLeft[2];
    }
    else if(frontRotationPosAngle){
        right[0]= dummyBottom[0];
        right[1]= dummyBottom[3];
        
        left[2] = dummyUp[3];
        left[3] =dummyUp[0];
        
        front[0] = dummyFront[1];
        front[1] = dummyFront[2];
        front[2] = dummyFront[3];
        front[3] = dummyFront[0];
        
        bottom[0] = dummyLeft[2];
        bottom[3] = dummyLeft[3];
        
        up[0] = dummyRight[1];
        up[3] = dummyRight[0];
    }
}
//can initiate randomization
//and control the looking of the whole rubic cube from keyboard
void
keyboard( unsigned char key,int x, int y )
{
    if(key == 'Q' | key == 'q')
        exit(0);
    else if(key == 'h' | key == 'H'){
        std::cout << "------------Here are the controlling instructions-------------- " <<std::endl;
        std::cout << " Exit from the program press 'q' " <<std::endl;
        std::cout << " -------------------------------------------------------------- " <<std::endl;
        std::cout << " For rotating the rubic cube in x-axis use keys 'w' and 's' " <<std::endl;
        std::cout << " For rotating the rubic cube in y-axis use keys 'a' and 'd' " <<std::endl;
        std::cout << " -------------------------------------------------------------- " <<std::endl;
        std::cout << " By clicking on 3 faces (right, front and up) " <<std::endl;
        std::cout << " with the mouse's right and left buttons, faces can be rotated " <<std::endl;
        std::cout << "" <<std::endl;
        std::cout << " Right click rotates faces with positive angle " <<std::endl;
        std::cout << " Left click rotates faces with negative angle " <<std::endl;
        std::cout << " -------------------------------------------------------------- " <<std::endl;
        std::cout << " For random configuration of the cube please press 'r" <<std::endl;
        std::cout << " -------------------------------------------------------------- " <<std::endl;
    }
    else if((key == 'r' | key == 'R') && !preventMultipleActions){
        randomButtonPressed=true;
        randomNumber=(rand()%20) + 15; //generates a number between 10 and 30 and applies that many random rotations
        preventMultipleActions=true;
    }
    else if((key == 'w' | key == 'W') && !preventMultipleActions){
        rotateRubicCubeUp=true;
        preventMultipleActions=true;
    }
    else if((key == 's' | key == 'S') && !preventMultipleActions){
        rotateRubicCubeDown=true;
        preventMultipleActions=true;
    }
    else if((key == 'a' | key == 'A') && !preventMultipleActions){
        rotateRubicCubeLeft=true;
        preventMultipleActions=true;
    }
    else if((key == 'd' | key == 'D') && !preventMultipleActions){
        rotateRubicCubeRight=true;
        preventMultipleActions=true;
    }
    
}


//----------------------------------------------------------------------------
//There are 9 different vao and model_view matrices. 8 for the subcubes
//And one holds all of them vao[8] and model_view[8]
//None of the rotations applied on model_view[8]
//so it remains in it's initial positioning
//it's up color is blue, front color is red and right color is magenta
//so by using model_view[8], rotation face can be determined.
//With the left or right button movement angle will be determined as well.
void mouse( int button, int state, int x, int y ){
    
    if ( state == GLUT_DOWN && button == GLUT_LEFT_BUTTON) {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glBindVertexArray( vao[8] );
        model_view[8] =(RotateX( initialXAngle ) * RotateY( initialYAngle ) * RotateZ(initialZAngle));
        glUniformMatrix4fv( ModelView, 1, GL_TRUE, model_view[8] );
        glDrawArrays( GL_TRIANGLES, 0, NumVertices );
        glFlush();
        
        y = glutGet( GLUT_WINDOW_HEIGHT ) - y;
        unsigned char pixel[4];
        glReadPixels(x, y, 1, 1, GL_RGB, GL_UNSIGNED_BYTE, pixel);
        
        if (pixel[0]==0 && pixel[1]==0 && pixel[2]==255 && !preventMultipleActions){//up blue
            upRotationPosAngle=true;
            preventMultipleActions=true;
        }
        else if(pixel[0]==255 && pixel[1]==0 && pixel[2]==0 && !preventMultipleActions){//front red
            frontRotationPosAngle=true;
            preventMultipleActions=true;
        }
        else if(pixel[0]==255 && pixel[1]==0 && pixel[2]==255 && !preventMultipleActions){//right magenta
            rightRotationPosAngle=true;
            preventMultipleActions=true;
        }
        glutPostRedisplay();
    }
    else if ( state == GLUT_DOWN && button == GLUT_RIGHT_BUTTON) {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glBindVertexArray( vao[8] );
        model_view[8] =(RotateX( initialXAngle ) * RotateY( initialYAngle ) * RotateZ(initialZAngle));
        glUniformMatrix4fv( ModelView, 1, GL_TRUE, model_view[8] );
        glDrawArrays( GL_TRIANGLES, 0, NumVertices );
        glFlush();
        
        unsigned char pixel[4];
        y = glutGet( GLUT_WINDOW_HEIGHT ) - y;
        glReadPixels(x, y, 1, 1, GL_RGB, GL_UNSIGNED_BYTE, pixel);
        
        if (pixel[0]==0 && pixel[1]==0 && pixel[2]==255 && !preventMultipleActions){//up blue
            upRotationNegAngle=true;
            preventMultipleActions=true;
        }
        
        else if(pixel[0]==255 && pixel[1]==0 && pixel[2]==0 && !preventMultipleActions){//front red
            frontRotationNegAngle=true;
            preventMultipleActions=true;
        }
        
        else if(pixel[0]==255 && pixel[1]==0 && pixel[2]==255 && !preventMultipleActions){//right magenta
             rightRotationNegAngle=true;
             preventMultipleActions=true;
        }
        glutPostRedisplay();
    }
}
//----------------------------------------------------------------------------
//3 different counters each controls different movement

int counterFor89Degrees = 0; //controls the face movements
int counterFor180Degrees = 0; //controls the rubic cube's x-axis movement in 180 degrees.
int counterFor90Degrees = 0; //controls the rubic cube's y-axis movement in 90 degrees.

int numberOfRandomRotations=0; //for making rotations randomNumber many times

//if one of the faces is choosen with the mouse or rubic cube rotation is choosen with one of the keys
//then it is corresponding field is set true.
//That many times rotation will be applied in display.
//And it is counted in timer
void timer( int p )
{
    //after rotation in desired degrees is done cubeArrays should be updated.
    //And counters should be reset for next rotations.
    if(counterFor90Degrees==90){ //if counterFor90Degrees==90 then 90 degree rotation of rubic's cube in y-axis is done
        updateCubeArrays();
        counterFor90Degrees=0;
        rotateRubicCubeRight=false;
        rotateRubicCubeLeft=false;
        preventMultipleActions=false;
    }
    if(counterFor180Degrees==180){ //if counterFor180Degrees==180 then 180 degree rotation of rubic's cube in x-axis is done
        updateCubeArrays();
        counterFor180Degrees=0;
        rotateRubicCubeDown=false;
        rotateRubicCubeUp=false;
        preventMultipleActions=false;
    }
    if(counterFor89Degrees==89){ //if counterFor89Degrees==89 then rotation of the subjected face is done
        updateCubeArrays();
        counterFor89Degrees=0;
        frontRotationPosAngle=false;
        frontRotationNegAngle=false;
        upRotationPosAngle=false;
        upRotationNegAngle=false;
        rightRotationPosAngle=false;
        rightRotationNegAngle=false;
        if(!randomButtonPressed){
            preventMultipleActions=false;
        }
    }
 //-------------------------------------------
    if((numberOfRandomRotations==randomNumber) && randomNumber!=0){ //if numberOfRandomRotations==randomNumber randomization is done
        numberOfRandomRotations=0;
        randomButtonPressed=false;
        preventMultipleActions=false;
    }
    
    if(frontRotationPosAngle || frontRotationNegAngle || upRotationPosAngle || upRotationNegAngle|| rightRotationPosAngle || rightRotationNegAngle)
        counterFor89Degrees++;
    
    if(rotateRubicCubeRight || rotateRubicCubeLeft)
        counterFor90Degrees++;
    
    if(rotateRubicCubeUp || rotateRubicCubeDown)
        counterFor180Degrees++;
    
    if(randomButtonPressed && counterFor89Degrees==0){
        numberOfRandomRotations++;
        int chooseRotationAxisAndAngle = (rand() % 6); //6 different movement choices. One should be determined with randomization
        
        if(chooseRotationAxisAndAngle==0) upRotationPosAngle=true;
        else if(chooseRotationAxisAndAngle==1) upRotationNegAngle=true;
        else if(chooseRotationAxisAndAngle==2) rightRotationPosAngle=true;
        else if(chooseRotationAxisAndAngle==3) rightRotationNegAngle=true;
        else if(chooseRotationAxisAndAngle==4) frontRotationPosAngle=true;
        else if(chooseRotationAxisAndAngle==5) frontRotationNegAngle=true;
    }
    
    glutPostRedisplay();
    glutTimerFunc(1,timer,0);
}
//----------------------------------------------------------------------------
int
main( int argc, char **argv )
{
    glutInit( &argc, argv );
    glutInitDisplayMode(  GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH | GLUT_3_2_CORE_PROFILE);
    glutInitWindowSize( 512, 512 );
    glutInitWindowPosition( 50, 50 );
    glutCreateWindow( "Rubik's Small Cube" );
    glewExperimental = GL_TRUE;
    glewInit();
    init();
    glutDisplayFunc( display ); // set display callback function
    glutReshapeFunc( reshape );
    glutMouseFunc( mouse );
    glutKeyboardFunc(keyboard);
    glutTimerFunc(10,timer,0);
    glutMainLoop();
    return 0;
}
