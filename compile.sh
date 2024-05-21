docker start TPE_ARQUI
docker exec -it TPE_ARQUI make clean -C/root/Toolchain
docker exec -it TPE_ARQUI make clean -C/root/
docker exec -it TPE_ARQUI make -C/root/Toolchain
docker exec -it TPE_ARQUI make -C/root/
docker stop TPE_ARQUI
