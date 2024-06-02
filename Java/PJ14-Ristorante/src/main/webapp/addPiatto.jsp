<form action="/PJ14-Ristorante/piatti" method="post">
	
	<div>
		<label>Nome Piatto</label>
		<input type="text" name ="nome">
	</div>
	
	<div>
		<label>Prezzo</label>
		<input type="number" step="0.01" name ="prezzo">
	</div>
	
	<div>
		<label>Categoria</label>
		<select name="categoria">
			<option value="1">Primi</option>
		</select>
	</div>
	
	<button type="submit" value="Add Piatto">Aggiungi</button>
</form>