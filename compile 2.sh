docker start arqui
docker exec -it arqui make clean -C/root/Toolchain
docker exec -it arqui make clean -C/root/
docker exec -it arqui make -C/root/Toolchain
docker exec -it arqui make -C/root/
docker stop arqui
