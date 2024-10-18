# Basic c/cpp socket code

## purpose

This code makes two end communicate with each other over a network thanks to socket.

in my example the server run and listening for any client, then a client connect to server , the server send a "hello from server" to acknowledge that the server hassuccefully connect to server.

## how to run it

1. **Compile and run the server first**

```bash
g++ server.cpp -o server
./server
```

2. **compile and run the client**

```bash
g++ client.cpp -o client 
./client
```
