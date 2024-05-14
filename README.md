# Teapot

## 소감
20210831 최우진 : 늘 자바스크립트로 해오던 작업을 C를 이용해서 만드니 새로웠습니다. freeglut를 적용하는 데에 어려움을 겪었지만 교수님께서 잘 가르쳐 주셔서 해결할 수 있었던 것 같습니다. 자바스크립트로 해본 걸 다시 해보는 느낌이라 아직까지는 그렇게 어렵지 않고 무난하게 할 수 있는 것을 느끼며 12주간 실력이 많이 늘었다는 것을 느낄 수 있었습니다.


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
![image](https://github.com/woojinchoi02/Graphics-Teapot/assets/162526228/84fc761f-a8fa-4591-84b0-879646e754b1)

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
