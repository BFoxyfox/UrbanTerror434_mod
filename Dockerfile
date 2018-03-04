FROM pedrxd/urbanterror-data:4.3.3

COPY build/release-linux-x86_64/titanMod.x86_64 /UrbanTerror43/titan-ded.x86_64
RUN chmod +x /UrbanTerror43/titan-ded.x86_64

RUN mkdir /server %% mkdir /server/q3ut4
COPY urt /bin/urt

ENTRYPOINT ["/bin/urt"]
