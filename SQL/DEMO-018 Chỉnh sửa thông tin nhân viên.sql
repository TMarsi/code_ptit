alter table Employees
modify column emp_id INT not null AUTO_INCREMENT,
modify column salary DECIMAL(12,2) not null default 0,
modify column status enum('ACTIVE','INACTIVE','RESIGNED') not null default 'ACTIVE',
add column employment_type enum('FULL_TIME','PART_TIME', 'INTERN') not null default 'FULL_TIME',
add column hire_date DATE,
drop column temp_info,
add primary key (emp_id);