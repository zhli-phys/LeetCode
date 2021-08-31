With home As (
    Select
        Teams.team_name,
        Case
            When home_team_goals > away_team_goals Then 3
            When home_team_goals = away_team_goals Then 1
            Else 0
        End As points,
        home_team_goals As goal_for,
        away_team_goals As goal_against,
        home_team_goals - away_team_goals As goal_diff
    From
        Teams
    Join
        Matches
    On
        Teams.team_id = Matches.home_team_id
),
away As (
    Select
        Teams.team_name,
        Case
            When away_team_goals > home_team_goals Then 3
            When away_team_goals = home_team_goals Then 1
            Else 0
        End As points,
        away_team_goals As goal_for,
        home_team_goals As goal_against,
        away_team_goals - home_team_goals As goal_diff
    From 
        Teams
    Join 
        Matches
    On  
        Teams.team_id = Matches.away_team_id
)
Select 
    team_name,
    Count(*) As matches_played,
    Sum(points) As points,
    Sum(goal_for) As goal_for,
    Sum(goal_against) As goal_against,
    Sum(goal_diff) As goal_diff
From 
    ((Select * From home) Union All (Select * From away)) as all_scores
Group By
    team_name
Order By
    points Desc, goal_diff Desc, team_name