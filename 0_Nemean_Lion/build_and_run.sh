# Before running this script, be ware!
# Make sure to install docker-machine and docker!
# Also make sure to have virtualbox installed.

#!/bin/zsh

docker-machine create -d virtualbox hercules
docker-machine start hercules
eval $(docker-machine env hercules)
docker build -t nemean_lion .
docker run --interactive --tty nemean_lion