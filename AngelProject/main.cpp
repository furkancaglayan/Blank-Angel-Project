#include <Angel_commons/Angel.h>

vec2 vertices[] = {vec2(.5f,0),vec2(-.5f,0),vec2(0,.5f)};
void init()
{
	GLuint vao;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);


	GLuint buffer;
	glGenBuffers(1, &buffer);
	glBindBuffer(GL_ARRAY_BUFFER, buffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);


	GLuint	program = InitShader("vshader.glsl", "fshader.glsl");
	glUseProgram(program);
	GLuint vPosition = glGetAttribLocation(program, "vPosition");
	glEnableVertexAttribArray(vPosition);
	glVertexAttribPointer(vPosition, 2, GL_FLOAT, GL_FALSE, 0, 0);



	glClearColor(0, 1, 0, 1);

}
void display(void) 
{
	glClear(GL_COLOR_BUFFER_BIT);
	glDrawArrays(GL_TRIANGLES, 0, 3);
	glFlush();

}
int main(int argc, char **argv) {

	glutInit(&argc, argv);

	unsigned int displayMode = GLUT_RGBA | GLUT_SINGLE ;
	glutInitDisplayMode(displayMode);
	glutInitWindowSize(600, 600);
	glutInitContextVersion(4, 3);
	glutInitContextProfile(GLUT_CORE_PROFILE);
	glutCreateWindow("Window name");
	glewExperimental = GL_TRUE;
	glewInit();
	


	init();



	glutDisplayFunc(display);
	glutMainLoop();


	return 1;
}