import sys
import csv
import os
import shutil
import inspect
import platform

def getSeparator() -> str:
    if platform.system() == "Linux":
        return "/"
    elif platform.system() == "Windows":
        return "\\"
    return ""

#python3 main.py initial_data/male_players_small.csv initial_data/male_teams_small.csv
class Player:
    
    def __init__(self, id: int, shortName: str, longName: str, ranking: int, potential: int, dateOfBirth: str, positions: str):
        self.a_id = id
        self.b_shortName = shortName
        self.c_longName = longName
        self.d_ranking = ranking
        self.e_potential = potential
        self.f_dateOfBirth = dateOfBirth
        self.g_positions = positions
        
    def __str__(self) -> str:
        res = ""
        for i in inspect.getmembers(self):
            if not i[0].startswith('_'):
                if not inspect.ismethod(i[1]): 
                    if "," in i[1]:
                        res += f'"{i[1]}",'
                    else:
                        res += f"{i[1]},"
        return f"{res[:-1]}\n"


class Team:
    
    def __init__(self, id: int, name: str):
        self.id = id
        self.name = name
        self.players: list[Player] = []
        
    def add_player(self, player: Player):
        self.players.append(player)

class League:
    def __init__(self, id: int, name: str, level: int):
        self.id = id
        self.name = name
        self.teams: list[Team] = []
        pass
    
    def add_team(self, team: Team):
        self.teams.append(team)
        

def main():
    if len(sys.argv) < 3:
        return
    
    leagues_map: dict[int, League] = {}
    team_map: dict[int, Team] = {}
    
    # teams
    with open(sys.argv[2], 'r') as teams:
        reader = csv.reader(teams)
        for row in reader:
            league_id = row[6]
            league: League = None
            if league_id in leagues_map.keys():
                league = leagues_map[league_id]
            else:
                league = League(league_id, row[7], row[8] if row[8] != '' else 0)
                leagues_map[league_id] = league
                
            team: Team = Team(row[0],row[5])
            team_map[team.id] = team
            league.add_team(team)
    
    # players
    with open(sys.argv[1], 'r') as players:
        reader = csv.reader(players)
        for row in reader:
            team_id = row[16]
            
            player: Player = Player(row[0], row[5], row[6], row[8], row[9], row[13], row[7])
            team_map[team_id].add_player(player)
            
    slash: str = getSeparator()
    shutil.rmtree("parsed_data")
    os.mkdir("parsed_data")
    os.mkdir(f"parsed_data{slash}leagues")
    for league in leagues_map.values():
        league_path = f"parsed_data{slash}leagues{slash}{league.id}_{league.name}"
        os.mkdir(league_path)
        for team in league.teams:
            team_path = league_path + f"{slash}{team.id}_{team.name}.csv"
            with open(team_path, "w") as team_file:
                for p in team.players:
                    team_file.write(f"{p}")
        pass
    
    
if __name__ == "__main__":
    main()

