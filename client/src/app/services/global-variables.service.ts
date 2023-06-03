import { Injectable } from "@angular/core";
import { GameMode, GameStage, GameStageResponse, GameState, Sign } from "../structs";
import { firstValueFrom } from "rxjs";
import { GameHttpClient } from "./game-http-client.service";

@Injectable({
	providedIn: "root",
})
export class GlobalVariablesService {
	gameStage: GameStage = GameStage.Unknown;
	private gameState: GameState = GameState.Unknown;
	isGameOngoing: boolean;
	isProcessing: boolean;
	playerMadeMove: boolean;
	playerChoseSegment: boolean;
	currentSegment: number | undefined = 5;
	boardSize: number = 3;
	playerSign: Sign = Sign.X; //TODO: Set the player sign when joining a game that has been already created
	gameMode: GameMode = GameMode.Multiplayer;

	//TODO: Remove
	enemySign: Sign = Sign.O;

	constructor(private readonly httpClient: GameHttpClient) {}

	isPlayerTurn(): boolean {
		return this.gameStage === GameStage.PlayerTurn;
	}

	playerChooseSegment(): boolean {
		return this.gameStage === GameStage.PlayerChooseSegment;
	}

	async canStartGame(): Promise<boolean> {
		this.gameState = await this.getGameState();
		return this.gameState === GameState.Ready;
	}
	async isPlayer(): Promise<boolean> {
		await this.getGameState();

		switch (this.gameState) {
			case GameState.Ready:
			case GameState.Waiting:
			case GameState.Ongoing:
			case GameState.Unknown:
				return false;
			case GameState.PlayerSolo:
			case GameState.PlayerX:
			case GameState.PlayerO:
				return true;
		}
	}
	async getGameState(): Promise<GameState> {
		this.gameState = await firstValueFrom(await this.httpClient.getGameState());
		switch (this.gameState) {
			case GameState.PlayerSolo:
			case GameState.PlayerX:
			case GameState.PlayerO:
				this.isGameOngoing = true;
				break;
		}
		return this.gameState;
	}
	async getGameStage(): Promise<GameStage> {
		this.gameStage = this.parseResponseGameStage(await this.httpClient.getGameStage());
		return this.gameStage;
	}

	parseResponseGameStage(response: GameStageResponse): GameStage {
		switch (response) {
			case GameStageResponse.Unknown:
				return GameStage.Unknown;
			case GameStageResponse.Finished:
				return GameStage.Finished;
			case GameStageResponse.PlayerX:
			case GameStageResponse.PlayerO:
				return response[7] == this.playerSign ? GameStage.PlayerTurn : GameStage.EnemyTurn;
			case GameStageResponse.PlayerXSegment:
			case GameStageResponse.PlayerOSegment:
				return response[7] == this.playerSign ? GameStage.PlayerChooseSegment : GameStage.EnemyChooseSegment;
		}
	}
}
