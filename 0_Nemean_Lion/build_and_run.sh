#!/bin/zsh
docker-machine restart hercules
eval $(docker-machine env hercules)
docker build -t nemean_lion .
docker run --interactive --tty nemean_lion