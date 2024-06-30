from app import db


class AttendanceRecord(db.Model):
    __tablename__ = 'AttendanceRecords'
    id = db.Column(db.Integer, primary_key=True)
    student_name = db.Column(db.String(100), nullable=False)
    date = db.Column(db.Date, nullable=False)
    status = db.Column(db.String(20), nullable=False)

    __table_args__ = {'extend_existing': True}
    def __repr__(self):
        return f"<AttendanceRecord(student_name='{self.student_name}', date='{self.date}', status='{self.status}')>"