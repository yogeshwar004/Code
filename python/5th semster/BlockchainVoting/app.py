from flask import Flask, render_template, request, jsonify
from blockchain import Blockchain

app = Flask(__name__)

blockchain = Blockchain()

@app.route('/')
def index():
    return render_template('index.html')

@app.route('/vote', methods=['POST'])
def vote():
    data = request.get_json()
    voter_id = data.get('voter_id')
    vote = data.get('vote')

    if not voter_id or not vote:
        return jsonify({'message': 'Voter ID and Vote are required'}), 400

    previous_hash = blockchain.get_previous_block()['hash']
    new_block = blockchain.create_block(voter_id, vote, previous_hash)
    
    return jsonify({'message': 'Vote added successfully!', 'block': new_block}), 201

@app.route('/get_chain', methods=['GET'])
def get_chain():
    return jsonify({'chain': blockchain.chain}), 200

@app.route('/is_valid', methods=['GET'])
def is_valid():
    valid = blockchain.is_chain_valid()
    return jsonify({'valid': valid}), 200

if __name__ == '__main__':
    app.run(debug=True)
