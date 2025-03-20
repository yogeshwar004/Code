import hashlib
import json
from datetime import datetime

class Blockchain:
    def __init__(self):
        self.chain = []
        self.create_block(voter_id="Admin", vote="Genesis", previous_hash="0")

    def create_block(self, voter_id, vote, previous_hash):
        block = {
            'index': len(self.chain) + 1,
            'timestamp': str(datetime.now()),
            'voter_id': voter_id,
            'vote': vote,
            'previous_hash': previous_hash,
            'hash': self.hash_block(voter_id, vote, previous_hash)
        }
        self.chain.append(block)
        return block

    def hash_block(self, voter_id, vote, previous_hash):
        data = f"{voter_id}{vote}{previous_hash}"
        return hashlib.sha256(data.encode()).hexdigest()

    def get_previous_block(self):
        return self.chain[-1]

    def is_chain_valid(self):
        for i in range(1, len(self.chain)):
            if self.chain[i]['previous_hash'] != self.chain[i - 1]['hash']:
                return False
        return True

# Testing the blockchain
blockchain = Blockchain()
print("First block:", blockchain.chain[0])

new_block = blockchain.create_block("Voter1", "Candidate_A", blockchain.get_previous_block()['hash'])
print("New vote added:", new_block)
