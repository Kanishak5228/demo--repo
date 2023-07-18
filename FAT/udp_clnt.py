import socket

def start_client():
    host = '127.0.0.1'
    port = 12345

    client = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

    while True:
        message = input("Your message: ").encode('utf-8')
        client.sendto(message, (host, port))
        response, server_address = client.recvfrom(1024)
        print(f"Received from server at {server_address[0]}:{server_address[1]}: {response.decode('utf-8')}")

    client.close()

if _name_ == "_main_":
    start_client()
