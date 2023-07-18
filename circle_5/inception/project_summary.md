
# Project Requirements

1. The project aims to broaden your knowledge of system administration using Docker. You need to virtualize several Docker images on your personal virtual machine.

2. All files required for the project configuration should be placed in a `srcs` folder.

3. A `Makefile` is required at the root of your directory. It should set up your entire application by building the Docker images using `docker-compose.yml`.

4. The project involves setting up a small infrastructure composed of different services under specific rules. All work has to be done in a virtual machine using docker compose.

5. Each Docker image must have the same name as its corresponding service, and each service has to run in a dedicated container. The containers should be built from the penultimate stable version of Alpine or Debian.

6. You must write your own `Dockerfile` for each service, and these `Dockerfiles` should be called in your `docker-compose.yml` by your `Makefile`. 

7. You are required to build the Docker images of your project yourself. Pulling ready-made Docker images is forbidden.

8. You need to set up the following Docker containers:
    - A container containing NGINX (using only TLSv1.2 or TLSv1.3)
    - A container containing WordPress + php-fpm (installed and configured) without nginx
    - A container containing only MariaDB without nginx
    - A volume containing your WordPress database
    - A second volume containing your WordPress website files
    - A `docker-network` that establishes the connection between your containers

9. Containers should restart in case of a crash.

10. There must be two users in your WordPress database, one of them being the administrator.

11. You should configure your domain name to point to your local IP address. The domain name should be `login.42.fr`, where `login` is your own login.

12. No password should be present in your Dockerfiles. It's mandatory to use environment variables.

13. Your NGINX container should be the only entry point into your infrastructure via the port 443 only, using the TLSv1.2 or TLSv1.3 protocol.

# Directory Structure

```
.
├── Makefile
└── srcs
    ├── .env
    ├── docker-compose.yml
    └── requirements
        ├── mariadb
        │   ├── conf
        │   ├── Dockerfile
        │   ├── .dockerignore
        │   └── tools
        ├── nginx
        │   ├── conf
        │   ├── Dockerfile
        │   ├── .dockerignore
        │   └── tools
        └── wordpress
            ├── conf
            ├── Dockerfile
            ├── .dockerignore
            └── tools
```

# Submission

Submit your work in your Git repository as usual. Only the work in your repository will be evaluated during the defense.
