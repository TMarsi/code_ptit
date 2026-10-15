create table TXN(
  TxnID int primary key,
  AccountID int not null,
  Amount DECIMAL(12,2) not null check(Amount > 0),
  Type ENUM('DEPOSIT','WITHDRAW') not null,
  TxnTime TIMESTAMP not null default current_timestamp,
  foreign key (AccountID) references ACCOUNT(AccountID)
);