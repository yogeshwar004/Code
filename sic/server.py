import socket

# Create a TCP/IP socket
server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

# Bind the socket to a specific address and port
server_address = ('localhost', 8888)
server_socket.bind(server_address)

# Listen for incoming connections
server_socket.listen(1)

print(f"Server listening on {server_address}")

while True:
    # Wait for a connection
    print("Waiting for a connection...")
    connection, client_address = server_socket.accept()

    try:
        print(f"Connection from {client_address}")

        # Receive data from the client
        data = connection.recv(1024)
        print(f"Received: {data.decode()}")

    finally:
        # Clean up the connection
        connection.close()
