# study allowed functions

- `open` : 파일을 사용하기 위해 열기(open)합니다.
```c
헤더: fcntl.h
형태: int open (const char *FILENAME, int FLAGS[, mode_t MODE])
인수:
    char *FILENAME 대상 파일 이름
    int FLAGS 파일에 대한 열기 옵션
    [, mode_t MODE] O_CREAT 옵션 사용에 의해 파일이 생성될 때 지정되는 파일 접근 권한
반환:
    int 0 < 파일 열기에 성공하면 파일 디스크립터의 양의 정수 값 반환
    ssize_t == -1 실패
  
예시: fd = open( "./test.txt", O_WRONLY | O_CREAT | O_EXCL, 0644)
 ```
- `close` : open()으로 열었던 파일을 닫아주는 함수입니다.
```c

헤더: nistd.h
형태: int close(int fd)
인수: int fd 닫고자 하는 파일의 파일 디스크립터
반환: 
    성공 시 0 리턴
    실패 시 -1 리턴 후 errno 설정

예시: close(fd)
```
- `read` : open() 함수로 열기한 파일의 내용을 읽기 합니다.
```c
헤더: unistd.h
형태: ssize_t read (int fd, void *buf, size_t nbytes)
인수:
    int fd 파일 디스크립터
    void *buf 파일을 읽어 들일 버퍼
    size_t nbytes 퍼버의 크기
반환:
    int 0 < 정상적으로 실행되었다면 읽어들인 바이트 수
    ssize_t == -1 실패

예시: read(fd, buff, BUFF_SIZE) 
```

- code example
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

- `write` : open() 함수로 열기를 한 파일에 쓰기를 합니다.
```c
헤더: unistd.h
형태: ssize_t write (int fd, const void *buf, size_t n)
인수: 
    int fd 파일 디스크립터
    void *buf 파일에 쓰기를 할 내용을 담은 버퍼
    size_t n 쓰기할 바이트 개수
반환: ssize_t 쓰기에 성공했다면 쓰기한 바이트 개수를, 실패했다면 -1을 반환

에시: write(fd, temp, strlen(temp))
```
- malloc
- free
- perror
- strerror
- access
- dup
- dup2
- execve
- exit
- fork
- pipe
- unlink
- wait
- waitpid