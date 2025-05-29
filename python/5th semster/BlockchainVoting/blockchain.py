import hashlib
import json
from datetime import datetime

class SmartContract:
    def __init__(self):
        self.rules = {
            'max_votes_per_voter': 1,
            'allowed_candidates': ['Candidate_A', 'Candidate_B', 'Candidate_C'],
            'voting_period': None
        }
        self.voter_records = {}
        self.candidate_votes = {
            'Candidate_A': 0,
            'Candidate_B': 0,
            'Candidate_C': 0
        }

    def validate_vote(self, voter_id, vote):
        if voter_id == "Admin" and vote == "Genesis":
            return True, "Genesis block allowed"

        if voter_id in self.voter_records:
            if self.voter_records[voter_id] >= self.rules['max_votes_per_voter']:
                return False, "Voter has already cast the maximum allowed votes"

        if vote not in self.rules['allowed_candidates']:
            return False, "Invalid candidate selection"

        return True, "Vote is valid"

    def record_vote(self, voter_id, vote):
        if voter_id == "Admin" and vote == "Genesis":
            return

        if voter_id not in self.voter_records:
            self.voter_records[voter_id] = 0
        self.voter_records[voter_id] += 1

        if vote in self.candidate_votes:
            self.candidate_votes[vote] += 1

class Blockchain:
    def __init__(self):
        self.chain = []
        self.smart_contract = SmartContract()
        self.create_block(voter_id="Admin", vote="Genesis", previous_hash="0")

    def create_block(self, voter_id, vote, previous_hash):
        is_valid, message = self.smart_contract.validate_vote(voter_id, vote)
        if not is_valid:
            raise ValueError(f"Smart Contract validation failed: {message}")

        self.smart_contract.record_vote(voter_id, vote)

        block = {
            'index': len(self.chain) + 1,
            'timestamp': str(datetime.now()),
            'voter_id': voter_id,
            'vote': vote,
            'previous_hash': previous_hash,
            'hash': self.hash_block(voter_id, vote, previous_hash),
            'smart_contract_state': {
                'rules': self.smart_contract.rules.copy(),
                'total_votes': sum(self.smart_contract.voter_records.values()),
                'candidate_votes': self.smart_contract.candidate_votes.copy()
            }
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
            current_block = self.chain[i]
            previous_block = self.chain[i - 1]

            if current_block['previous_hash'] != previous_block['hash']:
                return False

            if i > 1:
                expected_votes = previous_block['smart_contract_state']['total_votes'] + 1
                if current_block['smart_contract_state']['total_votes'] != expected_votes:
                    return False

        return True
