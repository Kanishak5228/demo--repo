import socket

def handle_client(client_socket):
    while True:
        data = client_socket.recv(1024).decode('utf-8')
        if not data:
            break

        print("Client:", data)

        response = input("Server response: ")
        client_socket.send(response.encode('utf-8'))

    client_socket.close()

def start_server():
    server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server_socket.bind(('localhost', 12345))
    server_socket.listen(5)
    print("Server is listening on localhost:12345")

    while True:
        client_socket, client_address = server_socket.accept()
        print("Connected to:", client_address)

        handle_client(client_socket)

if __name__ == "__main__":
    start_server()