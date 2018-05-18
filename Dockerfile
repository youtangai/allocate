FROM alpine:latest
WORKDIR /app
COPY allocate /app
ENTRYPOINT [ "./allocate" ]