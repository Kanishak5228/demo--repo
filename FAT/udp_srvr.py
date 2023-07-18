import socket

def start_server():
    server_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    server_socket.bind(('localhost', 12345))
    print("Server is listening on localhost:12345")

    while True:
        data, client_address = server_socket.recvfrom(1024)
        data = data.decode('utf-8')
        if not data:
            break

        print("Client:", data)

        response = input("Server response: ")
        server_socket.sendto(response.encode('utf-8'), client_address)

    server_socket.close()

if __name__ == "__main__":
    start_server()