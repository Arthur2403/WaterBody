#pragma once

void addWaterBody(vector<WaterBody>& waterBodyVector, WaterBody& newWaterBody);

void deleteWaterBody(vector<WaterBody>& waterBodyVector, WaterBody& newWaterBody);

void writeWaterBodyInTextFile(const string& fileName, vector<WaterBody>& waterBodyVector);

WaterBody fillWaterBody();

void menu();