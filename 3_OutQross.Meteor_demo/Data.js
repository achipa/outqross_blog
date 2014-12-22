function load() {
        statusText = "Connecting to server..."
        var jstodos = [];

        asteroid.subscribe("publicLists", function () {
            var listcollection = asteroid.getCollection("lists");
            var lquery = asteroid.reactiveQuery(listcollection);
            lists.json = Log.serialize(lquery.result);
            statusText = "ToDo lists retrieved";
            busy.visible = false;

            lquery.on("change", function(id) {
                busy.visible = true;
                console.log("QML lists sees " + id + "has changed!");
                lists.json = Log.serialize(lquery.result);
                busy.visible = false;
            });

            jstodos = [];

            // Subscribing for each ID separately only because the ToDo meteor example does not publish for multiple IDs
            for (var idx=0 ; idx < lquery.result.length; idx++) {
                asteroid.subscribe("todos", (function() {
                    todoscollection = asteroid.getCollection("todos");
                    var tquery = asteroid.reactiveQuery(todoscollection);
                    var tmp = Qt.createQmlObject("import QtQuick 2.0\nJSONListModel {}", appid, "dynamicModel");
                    tmp.json = Log.serialize(tquery.result.filter(
                                                 (function (element) {
//                                                     console.log(Log.serialize(element) + " " + lquery.result[this]._id);
                                                     if (element.listId === lquery.result[this]._id) return true; return false;
                                                 }).bind(this)
                                                 ));
                    tquery._myIdx = this;
                    jstodos.push(tmp);
                    todos = jstodos;
                    statusText = "ToDo items retrieved";

                    var update = function (id) {
                        busy.visible = true;
                        console.log("QML todos sees " + id + "has changed!");
                        if (id.indexOf("__upd__") === -1) {
                            jstodos[this._myIdx].json = Log.serialize(tquery.result.filter(
                                                 (function (element) {
//                                                     console.log(Log.serialize(element) + " " + lquery.result[this._myIdx]._id);
                                                     if (element.listId === lquery.result[this._myIdx]._id) return true; return false;
                                                 }).bind(this)
                                                 ).reverse());
                            todos = jstodos;
                        }
                        busy.visible = false;
                    }.bind(tquery);

                    tquery.on("change", update);
                }).bind(idx), lquery.result[idx]._id );
            }
        });

}

