import socket

def start_server():
    host = '127.0.0.1'
    port = 12345

    server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server.bind((host, port))
    server.listen(5)

    print(f"Server listening on {host}:{port}")

    client_socket, addr = server.accept()
    print(f"Accepted connection from {addr[0]}:{addr[1]}")

    while True:
        message = client_socket.recv(1024).decode('utf-8')
        if not message:
            break
        print(f"Received from client: {message}")
        response = input("Your response: ")
        client_socket.send(response.encode('utf-8'))

    client_socket.close()
    server.close()

if _name_ == "_main_":
    start_server()
