# study allowed functions

- open
```c
  - 헤더: `fcntl.h`
  - 형태: int open (const char *FILENAME, int FLAGS[, mode_t MODE])
  - 인수: 
    - `char *FILENAME` 대상 파일 이름
    - `int FLAGS` 파일에 대한 열기 옵션
    - `[, mode_t MODE]` O_CREAT 옵션 사용에 의해 파일이 생성될 때 지정되는 파일 접근 권한
  - 반환: 
    - int 0 < 파일 열기에 성공하면 파일 디스크립터의 양의 정수 값 반환
    - -1 == 실패
 ```
- close
- read
- write
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