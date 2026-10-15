select LEAST (HomeTeam,AwayTeam) as TeamA, GREATEST(HomeTeam,AwayTeam) as TeamB,avg(HomeAttendance + AwayAttendance) Avg_Total_Attendance 
from TeamStats
group by LEAST (HomeTeam,AwayTeam),GREATEST(HomeTeam,AwayTeam)
order by Avg_Total_Attendance desc,
teamA ASC,teamB asc
limit 3
