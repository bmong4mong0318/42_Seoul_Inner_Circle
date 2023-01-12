# study allowed functions

- `open` : 파일을 사용하기 위해 열기(open)합니다.
```c
헤더: fcntl.h
형태: int open (const char *FILENAME, int FLAGS[, mode_t MODE]);
인수:
    char *FILENAME: 대상 파일 이름
    int FLAGS 파일에: 대한 열기 옵션
    [, mode_t MODE]: O_CREAT 옵션 사용에 의해 파일이 생성될 때 지정되는 파일 접근 권한
반환:
    int 0 < 파일 열기에 성공하면 파일 디스크립터의 양의 정수 값 반환
    int == -1 실패
  
예시: fd = open( "./test.txt", O_WRONLY | O_CREAT | O_EXCL, 0644);
 ```
- `close` : open()으로 열었던 파일을 닫아주는 함수입니다.
```c

헤더: nistd.h
형태: int close(int fd);
인수: int fd: 닫고자 하는 파일의 파일 디스크립터
반환: 
    성공 시 0 리턴
    실패 시 -1 리턴 후 errno 설정

예시: close(fd);
```
- `read` : open() 함수로 열기한 파일의 내용을 읽기 합니다.
```c
헤더: unistd.h
형태: ssize_t read (int fd, void *buf, size_t nbytes);
인수:
    int fd: 파일 디스크립터
    void *buf: 파일을 읽어 들일 버퍼
    size_t nbytes: 퍼버의 크기
반환:
    int 0 < 정상적으로 실행되었다면 읽어들인 바이트 수
    ssize_t == -1 실패

예시: read(fd, buff, BUFF_SIZE); 
```
- `write` : open() 함수로 열기를 한 파일에 쓰기를 합니다.
```c
헤더: unistd.h
형태: ssize_t write (int fd, const void *buf, size_t n);
인수: 
    int fd: 파일 디스크립터
    void *buf: 파일에 쓰기를 할 내용을 담은 버퍼
    size_t n: 쓰기할 바이트 개수
반환: ssize_t 쓰기에 성공했다면 쓰기한 바이트 개수를, 실패했다면 -1을 반환

에시: write(fd, temp, strlen(temp));
```
- code example (open, close, read)
```c
#include <stdio.h>         // puts()
#include <string.h>        // strlen()
#include <fcntl.h>         // O_WRONLY
#include <unistd.h>        // write(), close()

#define  BUFF_SIZE   1024

int main()
{
   char   buff[BUFF_SIZE];
   int    fd;

   if ( 0 < ( fd = open( "./test.txt", O_RDONLY))){
      read( fd, buff, BUFF_SIZE);
      puts( buff);
      close( fd);
   } else {
      printf( "파일 열기에 실패했습니다.\n");
   }
   return 0;
}
```
---
- `malloc` : 메모리를 동적 할당합니다.
```c
헤더: stdlib.h
형태: void* malloc(size_t size);
인수: size_t: 동적으로 할당할 메모리의 크기
반환: 성공시 할당한 메모리의 첫번째 주소 리턴, 실패시 NULL리턴

예시: int* arr = (int*)malloc(sizeof(int) * 4);
```
- `free` : malloc()으로 할당한 메모리를 해제합니다. 
```c
헤더: stdlib.h
형태: void free(void *ptr);
인수: ptr: 해제하고자 하는 메모리의 포인터
반환: x

예시: free(arr);
```
- code example (malloc, free)
```c
#include <stdio.h>
#include <stdlib.h>

void main()
{
    int* arr;
    arr = (int*)malloc(sizeof(int) * 4); // size 4 동적할당

    arr[0] = 100;
    arr[1] = 200;
    arr[2] = 300;
    arr[3] = 400;

    for (int i = 0; i < 4; i++) {
        printf("arr[%d] : %d\n", i, arr[i]);
    }

    free(arr); //동적할당 해제
}
```
---
리눅스에는 시스템콜 및 라이브러리 함수를 수행하다가 오류가 발생하면 사용자의 프로그램으로 오류 결과를 넘겨준다.

사용자 프로그램에서는 함수의 리턴값을 조회함으로써 오류의 발생 여부를 확인 할 수 있다.

- 참고) 일반적으로 오류 발생 시 리턴값은 다음과 같다.
  - 시스템 콜 오류 시: -1
  - 라이브러리 함수 오류 시: NULL

<br>

- `perror` : 오류 메시지를 출력합니다.
```c
헤더: stdio.h
형태: void perror(const char *s);
인수: const char *s: 오류 메시지 앞에 덧붙이고 싶은 문자열
반환: x

예시: perror("ERROR");
```
- `strerror` : 오류 메시지를 출력합니다.
```c
헤더: string.h
형태: void strerror(int errnum);
인수: int errnum: 오류 메시지 앞에 덧붙이고 싶은 문자열
반환: 오류 번호에 해당하는 오류 문자열을 가리키는 포인터

예시: strerror(errno);
```
- code example (perror, strerror)
```c
#include <stdio.h>
#include <errno.h> //가장 최근에 발생한 에러 번호는 errno 변수에 있습니다.
#include <string.h>

void ListErrorMsg()
{
    int i = 0;
    char *errmsg;

    printf("== Error Message List ==\n");
    for(i=0;i<45;i++)
    {
        errmsg = strerror(i); //에러 메시지 확인
        printf("<%d>:%s\n",i,errmsg); //에러 번호와 에러 메시지 출력
    }
}

int main(void)
{
    FILE * fp;
    
    ListErrorMsg(); //에러 번호와 에러 메시지 목록 출력

    printf("\n없는 파일 읽기 모드로 열었을 때의 에러 메시지 확인하기\n");
    fp = fopen ("noexist.txt","rt");//읽기 모드로 없는 파일 열기
    if (fp == NULL)//파일 스트림이 NULL일 때
    {
        perror("file not existed");//에러 메시지 출력
        printf ("%d: %s\n",errno,strerror(errno));//에러 번호와 에러 메시지 출력
        return 0;
    }
    fclose(fp);
    return 0;
}
```
---
- `access` : 프로세스가 지정한 파일이 존재하는지, 읽거나 쓰거나 실행이 가능한 지를 확인하는 함수입니다. 만일 지정한 파일이 심볼릭 링크라면 링크의 원본을 체크합니다.
```c
헤더: unistd.h
형태: int access(const char *pathname, int mode);
인수:
    char *pathname: 파일이나 디렉토리 전체 이름
    int mode: 검사할 내용
반환:
    0 == 가능 또는 파일이 존재
    -1 == mode 에 대해 하나 이상 거절되었거나 에러가 있음. 자세한 내용은 errno에 세팅

예시: access(file_name, R_OK ¦ W_OK);
```
- code example (access)
```c
#include <stdio.h>
#include <unistd.h>

int main( void)
{
   char *file_name = "./test.c";

   if ( 0 == access( file_name, F_OK)){
      printf( "%s 파일이 있습니다.\n", file_name);
      
      if ( 0 == access( file_name, R_OK ¦ W_OK)){
         printf( "읽거나 쓰기가 가능합니다.\n");
      } else {
         printf( "읽지 못하거나 내용을 변경할 수 없습니다.\n");
      }
   }
}
```
---
- `dup` : fd로 전달받은 파일 서술자를 복제하여 반환합니다.
```c
헤더: unistd.h
형태: int dup(int fd);
인수:
    int fd: 복제 하고자하는 파일 디스크립터
반환:
    dup는 fd로 전달받은 파일 서술자를 복제하여 반환합니다.
    dup가 돌려주는 파일 서술자는 가장 낮은 서술자를 반환합니다.
    성공시 새 파일 서술자, 오류시 -1을 반환합니다.

예시: dup(fd);
```
- `dup2` : fd로 전달받은 파일 서술자를 복제하여 반환합니다.
```c
헤더: unistd.h
형태: int dup2(int fd, int fd2);
인수:
    int fd: 복제 하고자하는 파일 디스크립터
    int fd2: 복제 하고자하는 파일 디스크립터
반환:
    dup2는 새 서술자의 값을 fd2로 지정합니다.
    만일 fd2가 이미 열려있으면 fd2를 닫은 후 복제가 됩니다. 
    역시 성공시 새 파일 서술자, 오류시 -1을 반환합니다.

예시: dup(fd1, fd2);
```
- code example (dup, dup2)
```c
https://reakwon.tistory.com/104
```

- `execve` : 다른 프로그램을 실행하고 자신은 종료합니다.
```c
헤더: unistd.h
형태: int execle(const char *path, const char *arg , ..., char * const envp[]);
인수:
	char *char: 디레토리 포함 전체 파일 명
	const char *arg: 인수 목록
	char * const envp[]: 환경 설정 목록
반환: 실패일 때만 -1

예시: execve( "./show_envp", argv, envp);
```

- code example (exeve)
```c
#include <stdio.h>
#include <unistd.h>

int main()
{
   char *argv[]   = { "./show_envp", "HTTP", NULL};
   char *envp[]   = { "HTTP=badayak.com", NULL};

   execve( "./show_envp", argv, envp);

   printf( "이 메시지가 보이면 지정된 프로그램이 \
없거나 어떤 문제로 실행되지 못한 것입니다.\n");
}
```

- `exit` :  정상적으로 프로세스를 종료합니다.
```c
헤더: unistd.h
형태: void exit(int status);
인수: 
	int status: 호스트 환경에게 알려줄 종료 값
	- 정상 종료시 0
	- 에러로 인한 종료시 0이 아닌 숫자, 대체로 1
반환: x

예시: exit(0)
```

- `fork` : 현재 실행되는 프로세스에 대해 복사본 프로세스를 생성합니다.
  
  이때 원래 진행되던 프로세스는 부모 프로세스, 복사된 프로세스를 자식 프로세스라고 합니다.
```c
헤더: unistd.h
형태: pid_t fork(void)
인수: x
반환:
	pid_t -1 : 실패
	0 == 자식 프로세스, 새로 생성된 프로세스임
	0 < 생성된 자식 프로세스 PID

예시: ㅁㄴㅇㄹㅁㄴㅇㄹ
```

- `pipe` : 프로세스 간의 통신(IPC)에서 사용하는 파이프를 생성합니다.
```c
헤더: unistd.h
형태: int pipe(int filedes[2])
인수: int filedes[2] : 파이프의 입출력 디스크립터
반환: 
	0 == 성공,
	-1 == 실패
```
https://badayak.com/entry/C%EC%96%B8%EC%96%B4-%ED%8C%8C%EC%9D%B4%ED%94%84%EB%A5%BC-%EC%9D%B4%EC%9A%A9%ED%95%9C-IPC-%ED%95%A8%EC%88%98-pipe

- unlink
```c
``` 

- wait
```c
``` 

- waitpid
```c
``` 