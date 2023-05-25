import { HttpClient, HttpHeaders } from "@angular/common/http";
import { Injectable } from "@angular/core";
import { Observable, of } from "rxjs";
import { GameBoard, GameMode, GameStage, GameState, Sign } from "../structs";

@Injectable({
	providedIn: "root",
})
export class GameHttpClient {
	private url: string = "http://localhost:1337";

	constructor(private httpClient: HttpClient) {}

	setServerUrl(url: string): void {
		this.url = "http://" + url;
	}

	//#region POST
	postMakeMove(boardId: number, segmentId: number): Observable<any> {
		return this.httpClient.get<any>(this.url + "MakeMove", {
			withCredentials: true,
			params: {
				boardId: boardId,
				segmentId: segmentId,
			},
		});
	}
	postCreateGame(mode: GameMode, sign: Sign, size: number): Observable<boolean> {
		return this.httpClient.get<boolean>(this.url + "/CreateGame", {
			params: {
				gameMode: mode,
				playerSign: sign,
				boardSize: size,
			},
		});
	}
	postPickSegment(segmentNumber: number): Observable<boolean> {
		return this.httpClient.get<boolean>(this.url + "/PickSegment", {
			withCredentials: true,
			params: {
				segmentNumber: segmentNumber,
			},
		});
	}
	//#endregion

	//#region GET
	getBoardState(): Observable<GameBoard> {
		return this.httpClient.get<GameBoard>(this.url + "/BoardState", { withCredentials: true });
	}
	getServerStatus(): Observable<boolean> {
		return this.httpClient.get<any>(this.url + "/ServerStatus");
	}
	getGameState(): Observable<GameState> {
		return this.httpClient.get<GameState>(this.url + "/GameState", {
			withCredentials: true,
			headers: new HttpHeaders({
				"Content-Type": "text/plain",
			}),
		});
	}
	getGameStage(): Observable<GameStage> {
		return this.httpClient.get<GameStage>(this.url + "/GameStage", { withCredentials: true });
	}
	getEndGame(): Observable<boolean> {
		return this.httpClient.get<boolean>(this.url + "/EndGame", { withCredentials: true });
	}
	//#endregion
}
