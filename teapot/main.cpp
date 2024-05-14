#include <glut.h>
#include <gl/GLU.h>
#include <gl/GL.h>

float angleY = 0.0f;
float angleX = 0.0f;

void myDisplay() {
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glPushMatrix(); // 현재 변환 상태를 스택에 저장

    glRotatef(angleY, 0.0, 1.0, 0.0); // y축 주위로 회전
    glRotatef(angleX, 1.0, 0.0, 0.0); // x축 주위로 회전
    glColor3f (0.0f, 1.0f, 1.0f);
    glutWireTeapot(0.5);

    glPopMatrix(); // 스택에서 변환 상태를 가져옴

    glFlush();
}

void update(int value) {
    angleY += 2.0f; // y축 주위로 2도씩 회전
    angleX += 1.0f; // x축 주위로 1도씩 회전
    if (angleY > 360) {
        angleY -= 360; // 360도를 초과하지 않도록 조정
    }
    if (angleX > 360) {
        angleX -= 360; // 360도를 초과하지 않도록 조정
    }
    glutPostRedisplay(); // 디스플레이 콜백 함수 호출
    glutTimerFunc(25, update, 0); // 25ms마다 update 함수 호출
}

int main(int ac, char** av) {
    glutInit(&ac, av);
    glutInitDisplayMode(GLUT_RGB);
    glutCreateWindow("tea");
    glutDisplayFunc(myDisplay);
    glutTimerFunc(25, update, 0); // 타이머 함수를 통해 update 함수 주기적으로 호출
    glutMainLoop();
}
