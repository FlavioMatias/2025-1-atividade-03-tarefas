FROM fedora:latest

RUN dnf -y update && \
    dnf -y install findutils && \
    dnf -y install fish && \
    dnf -y install clear && \
    dnf clean all

RUN mkdir -p /app
COPY . /app
WORKDIR /app

CMD ["fish"]