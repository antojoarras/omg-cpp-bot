#include <dpp/dpp.h>

int main() {
    // Tu token del bot
    const std::string    BOT_TOKEN    = "TU_TOKEN_DE_BOT_AQUÍ";

    // Crear la instancia del bot
    dpp::cluster bot(BOT_TOKEN);

    // Evento: Cuando el bot está listo
    bot.on_log(dpp::utility::cout_logger());  // Para registrar los eventos en la consola

    // Evento: Cuando recibe un mensaje
    bot.on_message_create([&bot](const dpp::message_create_t &event) {
        if (event.msg.content == "!ping") {
            // Responder a "!ping" con "Pong!"
            bot.message_create(dpp::message(event.msg.channel_id, "Pong!"));
        }
    });

    // Conectar el bot al servidor
    bot.start(dpp::st_wait);
    return 0;
}
