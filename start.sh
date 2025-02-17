g++ -fPIC -shared -o libmylibrary.so shared.cpp
g++ -o main main.cpp -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 -ldl