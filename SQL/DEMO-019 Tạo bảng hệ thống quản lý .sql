create table LOAN(
  LoanID int primary key,
  MemberID int NOT NULL,
  BookID int NOT NULl,
  LoanDate date not null,
  DueDate date not null,
  ReturnDate date,
  Status ENUM('BORROWED','RETURNED','OVERDUE') not null default 'BORROWED',
  Fine DECIMAL(8,2) not null default 0,
  foreign key (MemberID) references MEMBER(MemberID),
  foreign key (BookID ) references BOOK(BookID)
);