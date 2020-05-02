FROM debian AS builder

WORKDIR /code/

RUN apt-get update
RUN apt-get install -y gcc make

#Build code
COPY ./ /code/
RUN make -j4

FROM pedrxd/urbanterror

COPY --from=builder /code/build/release-linux-x86_64/titanMod.x86_64 /data/UrbanTerror43/urbanterror-server
RUN chmod +x /data/UrbanTerror43/urbanterror-server
