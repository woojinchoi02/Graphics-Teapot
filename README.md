# Teapot

## openGL 주전자 구현
---------
사용법 Dev-cpp이용
1. Dev-cpp 설치
2. freeglut를 다운 받고 압축을 푼다.
3. 헤더 파일을 복사한다.
4. 라이브러리 파일을 연결한다.
ㄴ라이브러리 연결하는법 - dec프로젝트에서 프로젝트 옵션에 들어간 후 매개변수들 -> Linker: 아래의 [라이브러리나 객체 추가선택]
libfreeglut.a <-freeglut 폴더에 있음 libglu32.a, libopengl32.a <- Devcpp 폴더에 있음
5. dll 파일을 복사한다. 64비트 DII 파일을 c:\windows\system32에 복사한다.

## 주전자 실행 화면
![image](https://github.com/woojinchoi02/teapot/assets/162526228/1cd4d08b-1ad9-4b44-a82c-9fd33aec8b0b)
주전자가 X축과 Y축으로 회전합니다.

### 실행 코드
------
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

------
