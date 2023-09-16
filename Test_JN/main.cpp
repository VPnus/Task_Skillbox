#include <iostream>
#include <stdio.h>
#include <mqtt/client.h>

// Функция для получения данных о температуре по API
std::string getTemperatureData() {
    // TODO: выполнить запрос к API для получения данных о температуре
    // и вернуть полученные данные в виде строки
    return "Temperature data from API";
}

// Функция для отправки сообщений в MQTT брокер
void sendMQTTMessage(const std::string& topic, const std::string& message) {
    const std::string ADDRESS("ssl://test.mosquitto.org:8885");
    const std::string CLIENT_ID("mqtt_cpp_client");

    mqtt::client client(ADDRESS, CLIENT_ID);

    mqtt::ssl_options ssl_options;
    ssl_options.set_trust_store("../ca.crt");
    ssl_options.set_verify(true);

    client.set_tls(ssl_options);

    mqtt::connect_options conn_opts;
    conn_opts.set_keep_alive_interval(20);

    client.connect(conn_opts);
    client.publish(topic, message, 1, true);
    client.disconnect();
}

int main() {
    std::vector<std::string> stationIds = {"S50", "S107", "S60"};

    for (const std::string& stationId : stationIds) {
        std::string topic = "/api/temperature/" + stationId;
        std::string temperatureData = getTemperatureData();

        sendMQTTMessage(topic, temperatureData);
    }

    std::string statusTopic = "/api/status";
    std::string statusData = "api_info";

    sendMQTTMessage(statusTopic, statusData);

    return 0;
}