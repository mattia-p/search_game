# Search game engine

![Alt text](assets/search1.gif)

## Usage

Build docker image
```bash
docker compose build
```

Enter docker container
```bash
docker exec -it search_game-cpp-dev-1 /bin/bash
```

### Build

```bash
cd app/
mkdir build
cd build/
cmake ..
make
```

### Run
```bash
docker exec -it search_game-cpp-dev-1 /bin/bash
cd app/
cd build/
./game
```
Select a start position and goal on the map.

## Before running

From localhost:
```bash
xhost +
```

## Ideas for later

- Show path being explored live
- Make this run online?
- Automatic xhost + 
- Automated formatting
- Make user put the obstacles
- Reset button
- Make game bigger with more tiles
- Make it modular and let people choose size
- Generate random maze