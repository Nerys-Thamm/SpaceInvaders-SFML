#include "Data.h"



Data::Data()
{
}


Data::~Data()
{
}

void Data::from_json(const nlohmann::json & json, ScoreData & data)
{
	json.at("score").get_to(data.score);
	json.at("player").get_to(data.player);
	json.at("time").get_to(data.time);
}

void Data::to_json(nlohmann::json & json, const ScoreData & data)
{
	json["score"] = data.score;
	json["player"] = data.player;
	json["time"] = data.time;
}


