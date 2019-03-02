#!/bin/zsh
docker-machine create -d virtualbox hercules
docker-machine start hercules
eval $(docker-machine env hercules)
docker build -t nemean_lion .
docker run --interactive --tty nemean_lion