import socket

def start_server():
    host = '127.0.0.1'
    port = 12345

    server = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    server.bind((host, port))

    print(f"Server listening on {host}:{port}")

    while True:
        message, client_address = server.recvfrom(1024)
        print(f"Received from client at {client_address[0]}:{client_address[1]}: {message.decode('utf-8')}")
        response = input("Your response: ").encode('utf-8')
        server.sendto(response, client_address)

if _name_ == "_main_":
    start_server()
