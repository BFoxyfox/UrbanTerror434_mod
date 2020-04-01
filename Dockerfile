FROM pedrxd/urbanterror

COPY build/release-linux-x86_64/titanMod.x86_64 /data/UrbanTerror43/urbanterror-server
RUN chmod +x /data/UrbanTerror43/urbanterror-server
